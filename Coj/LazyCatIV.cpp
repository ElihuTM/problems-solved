#include <bits/stdc++.h>
#define maxf 92
#define maxn 100007

using namespace std;
typedef long long ll;

int n, q;
int ft[ maxn ];
bool is_son[ maxn ];
ll arr[ maxn ];
ll fib[ maxf ];

inline int LSOne( int n )
{ return n & -n; }

inline void update( int k, int v )
{
	while( k <= n )
	{
		ft[ k ] += v;
		k += LSOne( k );
	}
}

inline int query( int k )
{
	int tot = 0;
	while( k )
	{
		tot += ft[ k ];
		k -= LSOne( k );
	}
	return tot;
}

inline int lowerBoundI(int i, int j, ll valor)
{
	int m;
	while( j-i > 1)
	{
		m = i + (j-i)/2;
		if (fib[ m ] > valor)
			j = m;
		else
			i = m;
	}

	return i ;
}

inline bool is_fibSon( ll x )
{
	int i = 0, j = lowerBoundI( 0, maxf, x );
	ll aux;

	while( i < j )
	{
		aux = fib[ i ] + fib[ j ];
		if ( aux == x )
			return true;

		if ( aux < x )
			i++;
		else
			j--;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	bool c1;
	int a,b;
	ll c;

	fib[ 0 ] = fib[ 1 ] = 1;
	for (int i = 2; i < maxf; ++i)
		fib[ i ] = fib[ i-1 ] + fib[ i-2];

	cin >> n >> q;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[ i ];
		if( is_fibSon( arr[ i ] ) )
		{
			is_son[ i ] = true;
			update( i, 1 );
		}
	}

	for (int i = 0; i < q; ++i)
	{
		cin >> a >> b >> c;
		if ( a == 1)
			cout << query( c ) - query( b-1 ) << "\n";
		else
		{
			c1 = is_fibSon( c );

			arr[ b ] = c;
			if (  c1 and !is_son[ b ] )
			{
				update( b, 1 );
				is_son[ b ] = true;
			}
			else if( !c1 and is_son[ b ] )
			{
				update( b, -1 );
				is_son[ b ] = false;
			}
		}
	}


	return 0;
}