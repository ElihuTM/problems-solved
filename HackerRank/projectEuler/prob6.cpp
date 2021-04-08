#include <bits/stdc++.h>
#define maxn 10002

using namespace std;
typedef long long ll;

ll ans[ maxn ];

int main()
{
	int t, x;
	cin >> t;
		
	for( ll i = 0; i < maxn; ++i )
		ans[ i ] = ((i*(i+1))/2)*((i*(i+1))/2);
	
	ll aux = 0;
	for( int i = 0; i < maxn; ++i )
	{
		aux += i*i;
		ans[ i ] -= aux;
	}

	while( t-- )
	{
		cin >> x;
		cout << ans[ x ] << '\n';
	}
	
	return 0;
}
