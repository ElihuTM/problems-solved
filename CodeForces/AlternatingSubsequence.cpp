#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector< long long > arr;
	long long sum, val;
	int t, n;
	bool ban;

	cin >> t;
	while( t-- )
	{
		cin >> n;

		sum = 0; ban = false;
		arr.resize( n );
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		val = arr[ 0 ];
		for (int i = 1; i < n; ++i)
		{
			if ( arr[ i ] * arr[ i-1 ] > 0 )
				val = max( val, arr[ i ] );
			else
			{
				sum += val;
				val = arr[ i ];
			}
		}

		sum += val;
		cout << sum << '\n';
	}
	return 0;
}