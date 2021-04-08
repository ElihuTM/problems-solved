#include <bits/stdc++.h>
#define maxn 150003

using namespace std;

int arr[ maxn ];

int main()
{
	int t,n;
	cin >> t;

	while( t-- )
	{
		cin >> n;
		for( int i=0; i < n; ++i )
			cin >> arr[ i ];

		int mini = arr[ n-1 ], ans = 0;

		for( int i= n-2; i >= 0; --i )
		{
			if( arr[ i ] > mini )
				++ans;
			else
				mini = arr[ i ];
		}

		cout << ans << '\n';
	}
}
