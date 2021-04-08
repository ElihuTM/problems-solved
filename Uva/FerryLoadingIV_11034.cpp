#include <bits/stdc++.h>

using namespace std;


int main()
{
	map<string, int> lug;
	int t, n, l, k, ini;
	queue <int> q[ 2 ];
	string cad;

	lug[ "left" ] = 1;
	lug[ "right" ] = 0;

	cin >> t;
	while( t-- )
	{
		cin >> l >> n; l *= 100;

		cin >> k >> cad;
		q[ lug[ cad ] ].push( k );
		ini = 1;
		for (int i = 1; i < n; ++i)
		{
			cin >> k >> cad;
			q[ lug[ cad ] ].push( k );
		}

		int ans = 0;
		while( !q[ 0 ].empty() || !q[ 1 ].empty() )
		{
			int acum = 0;
			while( !q[ ini ].empty() && l-acum >= q[ ini ].front() )
			{
				acum += q[ ini ].front(); q[ ini ].pop();
			}

			ini = 1 - ini;
			++ans;
		}
		cout << ans << '\n';
	}
	return 0;
}