#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main()
{
	ll n, k;
	cin >> n >> k;

	vi arr( k );
	vi ans( k );

	ll sum = 0;
	for (int i = 0; i < k; ++i)
	{
		cin >> arr[ i ];
		sum += arr[ i ];
	}
	
	if ( sum < n )
		cout << "-1\n";
	else
	{
		bool is_pos = true;

		ans[ 0 ] = 0;
		ll pos = arr[ 0 ], n1 = n;
		ll ant = arr[ 0 ]-1;

		n -= arr[ 0 ];
		sum -= arr[ 0 ];

		for (int i = 1; i < k; ++i)
		{
			if ( arr[ i ] > n + ant )
			{
				is_pos = false;
				break;
			}

			if ( sum > n + ant )
			{
				ans[ i ] = ans[ i-1 ]+1;
				n = n1 - (ans[ i ] + arr[ i ]);
			}
			else if ( n == sum )
			{
				ans[ i ] = pos;
				n -= arr[ i ];
			}
			else
			{
				ans[ i ] = n1-sum;
				n = n1 - (ans[ i ] + arr[ i ]);
			}

			sum -= arr[ i ];
			ant = arr[ i ]-1;
			pos = ans[ i ] + arr[ i ];
		}

		if ( !is_pos )
			cout << "-1\n";
		else
		{
			cout << ans[ 0 ]+1;
			for (int i = 1; i < k; ++i)
				cout << ' ' << ans[ i ]+1;
			cout << '\n';
		}
	}

	return 0;
}	