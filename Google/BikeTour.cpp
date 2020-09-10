#include <bits/stdc++.h>

using namespace std;

int arr[ 105 ];

int main()
{
	int t, n;

	cin >> t;
	for (int c = 1; c <= t; ++c)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		int ans = 0;
		for (int i = 1; i < n-1; ++i)
			if ( arr[ i ] > arr[ i-1 ] && arr[ i ] > arr[ i+1 ] )
				ans++;

		cout << "Case #" << c << ": " << ans << '\n';
	}
	return 0;
}