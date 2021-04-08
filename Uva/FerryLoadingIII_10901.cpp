#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int, int> pii;

int main()
{
	map< string, int> lug;
	queue <int> q;
	int t, n, t, m;

	lug[ "left" ] = 1;
	lug[ "right" ] = 0;
	cin >> t;

	while( t-- )
	{
		cin >> n >> t >> m;

		for (int i = 0; i < m; ++i)
		{
			cin >> k >> cad;
			q.push( pii( k, lug[ cad ] ) );
		}

		int ini = 1, tim = 0;

		while( !q.empty() )
		{
			if ( q.front().ss != ini )
			{
				pii aux = q.front();
				int cont = 0;
				tim = q.front().ff + 2*t;
				while( aux == q.front() )
				{
					cout << tim << '\n';
				}
			}
		}
	}
	return 0;
}