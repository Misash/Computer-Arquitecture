#include<iostream>

using namespace std;

#define SIZE 10

void display(int X[], int n)
{
	for(int i=0; i<n; i++)
	{
		cout<<X[i];
	}
}

void sum(int X[], int Y[], int n)
{
	int carry=0, S[SIZE], count = n;
	count--;
	while(count>-1)
	{
		if(X[count]==0 && Y[count]==0 && carry==0)
		{
			S[count]=0;
		}
		else if(X[count]==0 && Y[count]==0 && carry==1)
		{
			S[count]=1;
			carry=0;
		}
		else if(X[count]==0 && Y[count]==1 && carry==0)
		{
			S[count]=1;

		}
		else if(X[count]==0 && Y[count]==1 && carry==1)
		{
			S[count]=0;
		}
		else if(X[count]==1 && Y[count]==0 && carry==0)
		{
			S[count]=1;
		}
		else if(X[count]==1 && Y[count]==0 && carry==1)
		{
			S[count]=0;
		}
		else if(X[count]==1 && Y[count]==1 && carry==0)
		{
			S[count]=0;
			carry=1;
		}
		else if(X[count]==1 && Y[count]==1 && carry==1)
		{
			S[count]=1;
			carry=1;
		}
		count--;
	}
	for(int i=0; i<n; i++)
	{
		X[i] = S[i];
	}
}

void complement(int X[], int Y[], int n)
{
	for(int i=0; i<n; i++)
	{
		if(X[i]==0)
			Y[i] = 1;
		else
			Y[i] = 0;
	}
}

void shifter(int X[], int Y[], int n)
{
	for(int i=n-1; i>0; i--)
		Y[i] = Y[i-1];
	Y[0] = X[n-1];
	for(int i=n; i>0; i--)
		X[i] = X[i-1];
}

int main()
{

	int A[SIZE], M[SIZE], _M[SIZE], Q[SIZE], _Q=0, count, i, size, N[2*SIZE];
	char c, str[SIZE];

	cout<<"Ingresa dos  numeros  (en binario):";
	cout<<"\nPrimer numero: ";scanf("%s", str);

	for(i=0; str[i]!='\0'; i++)
	{
		M[i] = str[i] - '0';
	}

	cout<<"Segundo numero: ";scanf("%s", str);


	for(i=0; str[i]!='\0'; i++)
	{
		Q[i] = str[i] - '0';
	}
	size = i;
	for(i=0; i<size; i++)
	{
		A[i]=0;
	}
	complement(M, _M, size);
	int one[SIZE];
	for(i=0; i<size-1; i++)
	{
		one[i]=0;
	}
	one[i]=1;
	sum(_M, one, size);

	count = size;

	while(count>0)
	{
		if(Q[size-1]==1 && _Q==0)
		{
			//A=A-M
			sum(A, _M, size);
		}
		else if(Q[size-1]==0 && _Q==1)
		{
			//A=A+M
			sum(A, M, size);
		}
		//Shift Right
		_Q = Q[size-1];
		shifter(A, Q, size);

		count--;
	}
	if(A[0]==1)
	{
		cout<<"\nProducto(negativo) : ";
		for(i=0; i<2*size; i++)
		{
			if(i<size)
				N[i] = A[i];
			else
				N[i] = Q[i-size];
			one[i]=0;
		}
		one[2*size-1]=1;
		complement(N, N, 2*size);
		sum(N, one, 2*size);
		display(N, 2*size);
	}
	else
	{
		cout<<"\nProducto : ";
		display(A, size);
		display(Q, size);
	}

}

