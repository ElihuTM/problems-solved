#include <algorithm>
#include <iostream>
#define maxn 2000007

using namespace std;

int arr[ maxn ];

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n;
	long long k;
	cin >> n >> k;

	++n;
	arr[ 0 ] = -1000000002;

	for (int i = 1; i < n; ++i)
		cin >> arr[ i ];

	sort( arr, arr+n );
	
	int i, j, mili = 1, ans = 0;
	i = j = n-1;

	while( i > 1 )
	{
		while( k - (arr[ j ] - arr[ i-1 ]) >= 0 )
			k -= (arr[ j ] - arr[ --i ]);
		
		if ( j-i+1 >= ans )
		{
			ans = j-i+1;
			mili = arr[ j ];
		}

		while( arr[ j ] == arr[ j-1 ] )
			--j;

		k += ( ( j - i ) * ( arr[ j ] - arr[ --j ] ) );

		if ( i > j )
			i = j;
	}

	cout << ans << " " << mili << endl;
	return 0;
}