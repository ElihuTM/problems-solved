#include <bits/stdc++.h>
#define ss second
#define ff first

using namespace std;
typedef pair <int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi lista;
map< int, pii > ap;

bool is_pos( int k )
{
	/*
	for (int i = 0; i < lista.size(); ++i)
		for (int j = 0; j < lista[ i ].size(); ++j)
			if ( lista[ i ][ j ] % k != i )
				return false;

	return true;
	*/

	for ( auto c: ap)
		if ( c.ss.ff != c.ss.ss )
			return false;
	return true;
}

int main()
{
	int t, n, k;
	vi arr;

	cin >> t;
	while( t-- )
	{
		cin >> n >> k;
		
		arr = vi( n );
		ap.clear();

		for (int i = 1; i <= n; ++i)
		{
			cin >> arr[ i ];
			ap[ arr[ i ] ].ff = i%k;	
		}

		sort( arr.begin(), arr.end() );

		for (int i = 1; i <= n; ++i)
			ap[ arr[ i-1 ] ].ss = i%k;

		if( is_pos( k ) )
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}