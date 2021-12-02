#include <bits/stdc++.h>
#define mod 998244353

using namespace std;
typedef long long ll;

ll suma( string a, int len2, int n )
{
	int len = a.size();
	ll ans = 0;
	ll b = 1;
	
	if( len <= len2 )
	{
		for( int i = len-1; i >= 0 ;--i )
		{
			ans = ans + ((((n*(a[ i ] - '0'))%mod) * ((b + (b*10)) % mod )) % mod) % mod;
			b = (b * 100) % mod; 
		}
	}
	else
	{
		for( int i = len-1; i >= len-len2 ;--i )
		{
			ans = ans + ((((n*(a[ i ] - '0'))%mod) * ((b + (b*10)) % mod )) % mod) % mod;
			b = (b * 100) % mod; 
		}

		for( int i = len-len2-1; i >= 0; --i )
		{
			ans = (ans + (((2 * n * ( a[i] - '0')%mod)*b ) % mod )) % mod;
			b = (b * 10) % mod;
		}
	}

	return ans;
}
int main()
{
	vector <string> arr[ 11 ];
	string cad;
	
	int n;
	cin >> n;

	for( int i = 0; i < n; ++i)
	{
		cin >> cad;
		arr[ cad.size() ].push_back( cad );
	}
	
	ll ans = 0;
	for( int i = 1; i <= 10; ++i )
	{
		for( int j = 0; j < arr[ i ].size(); ++j )
		{
			for( int k = 1; k<= 10 ; ++k )
			{
				ans += suma( arr[ i ][ j ], k, arr[ k ].size() );
				ans %= mod;
			}

//			cout << arr[ i ][ j ] << ": " << ans << endl;
		}
	}

	cout << ans << '\n';
	return 0;
}
