#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;
typedef vector<int> vi;

vi criba;
bitset<maxn> visit;

llenar()
{
	criba = vi( maxn );
	criba[ 0 ] = criba[ 1 ] = 1;
	for (int i = 0; i < maxn; ++i)
		criba[ i ] = i;

	for (long long i = 2; i < maxn; ++i)
		if ( criba[ i ] == i )
			for (long long j = i*i; j < maxn; j+=i)
				if ( i < criba[ j ] )
					criba[ j ] = i;
}

void normalizar( int &x )
{
	vi fact;
	while( x > 1 )
	{
		fact.push_back( criba[ x ] );
		x /= criba[ x ];
	}

	x = 1;
	for (int i = 0; i < fact.size(); ++i)
	{
		if ( i < fact.size()-1 && fact[ i ] == fact[ i+1 ] )
		{
			++i;
			continue;
		}

		x *= fact[ i ];
	}
}

int exist_cuadrados( vi &arr )
{
	vi ans;
	for (int i = 0; i < arr.size(); ++i)
		if ( arr[ i ] == 1 )
			return 1;

	set<int> exist;
	for (int i = 0; i < arr.size(); ++i)
	{
		if ( exist.find( arr[ i ] ) != exist.end() )
			return 2;

		exist.insert( arr[ i ] );
	}

	return 3;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	llenar();

	int n;
	cin >> n;

	vi arr( n );
	map<int, vector<int> > lista;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[ i ];
		normalizar( arr[ i ] );
	}

	op = exist_cuadrados( arr );

	if ( op < 3 )
		cout << op << '\n';
	else
	{
		int u;
		for (int i = 0; i < n; ++i)
		{
			u = criba[ arr[ i ] ];
			if ( u != arr[ i ] )
			{
				lista[ u ].push_back( arr[ i ] / u );
				lista[ arr[ i ] / u ].push_back( u );
			}
		}

		
	}
	return 0;
}