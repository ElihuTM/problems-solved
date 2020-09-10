#include <bits/stdc++.h>
#define mod 998244353

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int n, k;

ll sum( vi arr, set<int> &val )
{
	sort( arr.rbegin(), arr.rend() );
	ll ans = 0;
	for (int i = 0; i < k; ++i)
	{
		ans += arr[ i ];
		val.insert( arr[ i ] );
	}

	return ans;
}

int main()
{

	cin >> n >> k;
	vi arr( n );
	vi otr;

	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	ll suma = 0, cont = 1;
	set<int> val;

	suma = sum( arr, val );
	for (int i = 0; i < n; ++i)
		if ( val.find( arr[ i ]) != val.end() )
			otr.push_back( i );
	
	for (int i = 0; i < otr.size()-1; ++i)
		cont = (cont * (otr[ i+1 ] - otr[ i ] )) % mod;
	
	cout << suma << ' ' << cont << '\n';

	return 0;
}