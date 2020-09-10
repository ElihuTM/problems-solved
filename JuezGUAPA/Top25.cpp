#include <bits/stdc++.h>
#define maxn 1000007

using namespace std;
typedef vector<int> vi;

string a[ maxn ];
string b[ maxn ];
int padre[ maxn ];
int tam[ maxn ];

int padrote( int u ){
	return (u == padre[ u ] ? u : padre[ u ] = padrote( padre[ u ] ) );
}

bool union_find( int a, int b )
{
	a = padrote( a );
	b = padrote( b );

	if ( a == b ) return false;
	
	if ( a > b )
	{
		padre[ b ] = a;
		tam[ a ] += tam[ b ];
	}
	else
	{
		padre[ a ] = b;
		tam[ b ] += tam[ a ];
	}
	return true;
}

int main()
{
	map<string, int> names;
	int n;

	cin >> n;

	// limpiar el union find	
	for (int i = 1; i <= n; ++i)
	{
		tam[ i ] = 1;
		padre[ i ] = i;
	}
	
	// leer a
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[ i ];
		names[ a[ i ] ] = i;
	}
	
	// leer b
	for (int i = 1; i <= n; ++i)
	{
		cin >> b[ i ];
		union_find( names[ a[ i ] ], names[ b[ i ] ] );
	}
	
	//Principal
	int pos = 1, ant = 0, ult;
	while( pos <= n )
	{
		// la posicion en la que me encuentro
		ult = padrote( pos );

		if( tam[ ult ] + ant == ult )
		{
			cout << tam[ ult ] << '\n';
			ant = tam[ ult ] + ant;
			pos = ult+1;
		}
		else
		{
			union_find( pos, pos+1 );
			++pos;
		}
	}
	return 0;
}

/*
1: A A 1

2: D C x
3: B B x
4: E F 5
5: C D
6: F E
7:

1:
0

5:
1 -> 4
|
2
|
3 -> 5

*/	
