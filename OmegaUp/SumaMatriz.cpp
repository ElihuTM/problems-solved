#include <iostream>
#include <cstdio>
#include <cstring>
#define maxtam 505

using namespace std;

int N,M;
int ft[maxtam][maxtam];

int LSOne(int b)
{
	return(b & (-b));
}
int consultar(int i, int j)
{
	int total = 0;
	int a = i, b = j;
	while(a and b)
	{
		total -= ft[a][b];
		int x = a, y= b;
		while(x)
		{
			total += ft[x][y];
			x -= LSOne(x);
		}

		x = a, y = b;
		while(y)
		{
			total += ft[x][y];
			y -= LSOne(y);
		}

		a -= LSOne(a);
		b -= LSOne(b);
	}
	return total;
}
void adjust(int a, int b, int v)
{
	int i = a;
	while(i <= N)
	{
		int j = b;
		while(j <= M)
		{
			ft[i][j] += v;
			j += LSOne(j);
		}
		i += LSOne(i);
	}
}	


int main()
{
	int tabla[maxtam][maxtam];
	memset(tabla,0,sizeof(tabla));
	memset(ft,0,sizeof(ft));
	int casos, opcion, a, b, c, d, valor;
	
	scanf("%i %i",&N,&M);
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			scanf("%i",&tabla[i][j]);
			adjust(i,j,tabla[i][j]);
		}

	scanf("%i",&casos);
	while(casos--)
	{
		scanf("%i",&opcion);
		if (opcion)
		{

			scanf("%i %i %i",&a,&b,&valor);	
			c = valor - tabla[a][b];
			tabla[a][b] = valor;
			adjust(a,b,c);
		}
		else
		{
			int res = 0;
			scanf("%i %i %i %i",&a,&b,&c,&d);
			res = consultar(c,d);
			res -= consultar(a-1,d);
			res -= consultar(c,b-1);
			res += consultar(a-1,b-1);
 			printf("%i\n",res);
		}
	}
	return 0;
}