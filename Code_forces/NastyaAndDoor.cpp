#include <bits/stdc++.h>
#define maxn 200017

using namespace std;

int arr[ maxn ];

int main()
{
	int t, n, k, current, pos, ans, ansp;

	cin >> t;
	while( t-- )
	{
		cin >> n >> k;
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];
		
		current = pos = 0;
		for (int i = 1; i < k-1; ++i)
			if ( arr[ i ] > arr[ i-1 ] && arr[ i ] > arr[ i+1 ] )
				++current;

		++pos;
		ans = current;
		ansp = 0;
		while( pos <= n-k )
		{
			if( arr[ pos ] > arr[ pos-1 ] && arr[ pos ] > arr[ pos+1 ] )
				--current;

			if( arr[ pos+k-2 ] > arr[ pos+k-3 ] && arr[ pos+k-2 ] > arr[ pos+k-1 ] )
				++current;

			if ( current > ans )
			{
				ans = current;
				ansp = pos;
			}
			++pos;
		}

		cout << ans+1 << ' ' << ansp+1 << '\n';
	}
	return 0;
}