#include <bits/stdc++.h>
#define maxn 10005

using namespace std;
typedef pair <int,int> pii;

int arr[ maxn ];

int main()
{
	int n, m;

	while( cin >> n )
	{
		for( int i = 0; i < n; ++i )
			cin >> arr[ i ];
		
		cin >> m;

		sort( arr, arr + n );
		
		int i = 0, j = n-1;
		pii ans;

		while( i < j )
		{
			if( arr[ i ] + arr[ j ] == m )
			{
				ans = make_pair( arr[ i ], arr[ j ] );
				++i; --j;
			}
			else if( arr[ i ] + arr[ j ] > m )
				--j;
			else
				++i;
		}
		
		cout << "Peter should buy books whose prices are " << ans.first << " and " << ans.second << ".\n\n";
	}
	return 0;
}
