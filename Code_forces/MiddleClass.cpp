#include <bits/stdc++.h>
#define maxn 100007

using namespace std;
typedef long long ll;

int arr[ maxn ];

bool f( int a, int b ) {
	return a > b;
}

int main()
{
	int t, n, x, ans;
	cin >> t;
	while( t-- )
	{
		cin >> n >> x;
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		sort( arr, arr+n, f );

		ll sum = ans = 0;
		for (int i = 0; i < n; ++i)
		{
			if ( arr[ i ] >= x)
			{
				sum += arr[ i ]-x;
				++ans;
			}
			else
			{
				if ( arr[ i ]+sum >= x)
				{
					sum -= x-arr[ i ];
					++ans;
				}
				else
					break;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}	
	