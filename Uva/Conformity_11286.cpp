#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef pair <ll, int> pii;

int main()
{
	int n;
	map< ll, int > dic;
	int arr[ 5 ];
	ll aux;

	cin >> n;
	while( n )
	{
		dic.clear();
		for( int i = 0; i < n; ++i )
		{
			aux = 0;
			for( int j = 0; j < 5; ++j )
				cin >> arr[ j ];

			sort( arr, arr+5 );
			for( int j = 0; j < 5; ++j )
				aux = (aux*1000) + arr[ j ];

			++dic[ aux ];
		}

		pii ans(0,0);
		for( auto c: dic )
		{
			if( c.ss == ans.ff )
				ans.ss += c.ss;
			else if( c.ss > ans.ff )
				ans = make_pair( c.ss, c.ss );
		}

		cout << ans.ss << '\n';

		cin >> n;
	}
}
