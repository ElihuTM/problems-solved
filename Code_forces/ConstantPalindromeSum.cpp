#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector <ll> vi;

int main()
{
	ll t, n, k;
	vi tree;
	vi arr;

	cin >> t;
	while( t-- )
	{
		cin >> n >> k;

		tree.assign( 2*k+2, 0 );
		arr.resize( n );
		
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		for (int i = 0; i < n/2; ++i)
		{
			int r = max( arr[ i ], arr[ n-i-1] );
			int l = min( arr[ i ], arr[ n-i-1] );
			
			tree[ 0 ] += 2;
			tree[ l+1 ]--;
			tree[ l+r ]--;

			tree[ r+k+1 ]++;
			tree[ l+r+1 ]++; 
		}

		ll ans = tree[ 0 ];	
		for (int i = 1; i <= 2*k ; ++i)
		{
			tree[ i ] += tree[ i-1 ];
			ans = min( ans, tree[ i ] );
		}
		cout << ans << '\n';
	}
	return 0;
}