#include <bits/stdc++.h>
#define maxn 1003

using namespace std;

int arr[ maxn ];

int main()
{
	int n, sum, ans;
	double aux;

	cin >> n;
	while( n )
	{
		ans = sum = 0;
		for( int i = 0; i < n; ++i )
		{
			cin >> aux;
			arr[ i ] = round( aux * 100 );
			sum += arr[ i ];
		}
		
		sum /= n;
		sort( arr, arr+n );

		for( int i = 0; i < n; ++i)
			if( arr[ i ] < sum )
				ans += sum - arr[ i ];

		cout << '$' << ans/100 << '.';
		if( ans%100 < 10 )
			cout << 0;

		cout << ans%100 << '\n';
		cin >> n;
	}
}
