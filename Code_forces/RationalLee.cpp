#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, k;
	vector <int> numero;
	vector <int> persona;
	cin >> t;

	while( t-- )
	{
		cin >> n >> k;
		numero.resize( n );
		persona.resize( k );
		int unos = 0;

		for( int i = 0; i<n; ++i )
			cin >> numero[ i ];

		for( int i = 0; i<k; ++i )
		{
			cin >> persona[ i ];
			if( persona[ i ] == 1 )
				unos++;
		}

		sort( numero.begin(), numero.end() );
		sort( persona.rbegin(), persona.rend() );

		long long ans = 0;
		for( int i = 0; i < k; ++i )
		{
			ans += numero.back();
			if( unos )
			{
				ans += numero.back();
				--unos;
			}

			numero.pop_back();
		}
		n -= k;

		int i = 0, m = 0;
		while( i < n )
		{
			ans += numero[ i ];
			i += persona[ m ] - 1;
			++m;
		}

		cout << ans << '\n';
	}
	return 0;
}
