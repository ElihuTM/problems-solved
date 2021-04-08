#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll arr[ 3 ];
	ll q, ans;

	cin >> q;
	while( q-- )
	{
		cin >> arr[ 0 ] >> arr[ 1 ] >> arr[ 2 ];
		sort( arr, arr + 3 );

		ans = arr[ 1 ];
		arr[ 2 ] -= arr[ 1 ] - arr[ 0 ];
		ans += arr[ 2 ]/2;

		cout << ans << '\n';
	}
	return 0;
}
