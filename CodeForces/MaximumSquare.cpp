#include <bits/stdc++.h>
#define maxn 1005

using namespace std;

int main()
{
	int t,n;
	vector<int> arr;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		arr.resize( n );

		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		sort( arr.rbegin(), arr.rend() );

		int ans = 0, aux;
		for (int i = 0; i < n; ++i)
		{
			aux = min( i+1, arr[ i ] );
			ans = max( aux, ans );
		}

		cout << ans << '\n';
	}
	return 0;
}