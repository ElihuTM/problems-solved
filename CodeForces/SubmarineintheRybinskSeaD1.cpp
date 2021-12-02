#include <bits/stdc++.h>
#define mod	998244353

using namespace std;
typedef long long ll;

int n;

ll f( string a )
{
	ll ans = 0;
	ll b = 1;
	int len = a.size();

	for( int i = len-1; i >= 0 ;--i )
	{
		ans = ans + ((((n*(a[ i ] - '0'))%mod) * ((b + (b*10)) % mod )) % mod) % mod ;
		b = (b * 100) % mod;
	}
	
	return ans;
}

int main()
{
	string a;
	ll ans = 0;

	cin >> n;
	for( int i = 0; i < n; ++i )
	{
		cin >> a;
		ans = (ans + f( a )) % mod;
	}
	
	cout << ans << '\n';
	return 0;
}
