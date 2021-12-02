#include <bits/stdc++.h>
#define l(p) p<<1
#define r(p) (p<<1)+1
#define mid(i,j) ((i+j)>>1)
#define endl '\n'

using namespace std;
typedef long long ll;

struct nodo
{
	ll faltantes = 0;
	ll sobrantes = 0;
	ll vendidos = 0;

	nodo operator + ( nodo &p )
	{
		nodo aux;
		if( sobrantes >= p.faltantes )
		{
			aux.faltantes = faltantes;
			aux.sobrantes = sobrantes - p.faltantes + p.sobrantes;
			aux.vendidos = vendidos + p.vendidos + p.faltantes;
		}
		else
		{
			aux.faltantes = faltantes + p.faltantes-sobrantes;
			aux.sobrantes = p.sobrantes;
			aux.vendidos = vendidos + p.vendidos + p.sobrantes;
		}
		return aux;
	}

	void act()
	{
		if( sobrantes && faltantes )
		{
			if( sobrantes >= faltantes )
			{
				sobrantes -= faltantes;
				vendidos += faltantes;
				faltantes = 0;
			}
			else
			{
				faltantes -= sobrantes;
				vendidos += sobrantes;
				sobrantes = 0;
			}
		}
	}
};

nodo m_n( ll a, ll b, ll c )
{
	nodo aux;
	aux.faltantes = a;
	aux.sobrantes = b;
	aux.vendidos = c;
	return aux;
} 

struct segment_tree
{
	vector <nodo> arbol;

	void build( int p, int i, int j, int value )
	{
		if( i == j )
		{
			arbol[ p ] = m_n( 0, value, 0 );
			return ;
		}

		build( l(p), i, mid(i,j), value );
		build( r(p), mid(i,j)+1, j, value );

		arbol[ p ] = arbol[ l(p) ] + arbol[ r(p) ];
	}
	
	nodo query( int p, int i, int j, int a, int b )
	{
		if( i > b || j < a )
			return m_n(0,0,0);

		if( i >= a && j <= b )
			return arbol[ p ];

		nodo left = query( l(p), i, mid(i,j), a, b);
		nodo right = query( r(p), mid(i,j)+1, j, a, b);

		return left + right;
	}

	void update( int p, int i, int j, int d, int value )
	{
		if( i > d || j < d )
			return;
		
		if( i == d && j == d )
		{
			arbol[ p ].faltantes += value;
			arbol[ p ].act();

			return;
		}

		update( l(p), i, mid(i,j), d, value );
		update( r(p), mid(i,j)+1, j, d, value );

		arbol[ p ] = arbol[ l(p) ] + arbol[ r(p) ];
	}
};

int main()
{
	int n, k, a, b, q, op;
	nodo aux_a;
	nodo aux_b;
	nodo ans;

	cin >> n >> k >> a >> b >> q;
	
	segment_tree seg_a;
	segment_tree seg_b;
	
	seg_a.arbol = vector <nodo>( 6*n );
	seg_b.arbol = vector <nodo>( 6*n );
	seg_a.build( 1, 0, n-1, a );
	seg_b.build( 1, 0, n-1, b );

	while( q-- )
	{
		cin >> op;
		if( op == 1)
		{
			cin >> a >> b;
			seg_a.update( 1, 0, n-1, a-1, b );
			seg_b.update( 1, 0, n-1, a-1, b );
		}
		else
		{
			cin >> a;
			if( a == 1 )
			{
				aux_a = seg_a.query( 1, 0, n-1, k, n-1 );
				cout << aux_a.vendidos << endl;
			}
			else if( a == n-k+1 )
			{
				aux_b = seg_b.query( 1, 0, n-1, 0, a-2 );
				cout << aux_b.vendidos << endl;
			}
			else
			{
				aux_b = seg_b.query( 1, 0, n-1, 0, a-2 );
				aux_a = seg_a.query( 1, 0, n-1, a+k-1, n-1);
				ans = aux_b + aux_a;
				cout << ans.vendidos << endl;
			}
		}

	}
	return 0;
}
