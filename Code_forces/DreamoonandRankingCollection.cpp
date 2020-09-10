#include <bits/stdc++.h>
#define maxn 205

using namespace std;

bitset<maxn> day;

int main()
{
	int t, n, x, a;
	cin >> t;

	while( t-- )
	{
		cin >> n >> x;
		day.reset();

		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			day[ a ] = true;
		}

		for (int i = 1; i < maxn; ++i)
		{
			if ( !day[ i ] && x > 0)
			{
				day[ i ] = true;
				--x;
			}

			if ( !day[ i ] && x == 0)
				break;
		}

		int ans;
		for (int i = 1; i < maxn; ++i)
			if ( !day[ i ])
			{
				ans = i-1;
				break;
			}

		cout << ans << '\n';
	}
	return 0;
}	