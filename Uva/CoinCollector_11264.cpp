#include <bits/stdc++.h>
#define maxn 1005

using namespace std;
typedef long long ll;

ll arr[ maxn ];

int main()
{
	int t, n;
	cin >> t;

	while( t-- )
	{
		ll sum = 0;
		int cont = 0;

		cin >> n;
		for( int i = 0; i < n; ++i)
		{
			cin >> arr[ i ];
			sum += arr[ i ] + arr[ i ] - 1;
		}

		for( int i = n-1; i >= 0; --i )
		{	
			if( arr[ i ] <= sum )
				++cont;

			sum = sum % arr[ i ];
		}

		cout << cont << '\n';
	}
	return 0;
}
