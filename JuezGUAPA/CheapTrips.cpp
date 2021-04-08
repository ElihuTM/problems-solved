#include <bits/stdc++.h>
#define maxn 10007

using namespace std;
typedef long long ll;
typedef pair< int, ll > pii;

ll tabla[ maxn ][ 6 ];
pii arr[ maxn ];
ll ans[ maxn ];

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, tiempo, it, itj;
	ll acum;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[ i ].first >> arr[ i ].second;
		arr[ i ].second *= 100;	
	}

	for( int i=0; i < n ; ++i)
	{
		tabla[ i ][ 0 ] = arr[ i ].second;
		tabla[ i ][ 1 ] = arr[ i ].second/2;
		for( int j = 2; j<6; ++j)
			tabla[ i ][ j ] = arr[ i ].second/4;
	}

	ans[ n ] = 0;
	for( int i = n-1 ;  i >=0; --i )
	{
		ans[ i ] = arr[ i ].second + ans[ i+1 ];
		tiempo = 120; it = i; itj = 0; acum = 0;

		while( tiempo > 0 && it < n && itj < 6)
		{
			acum += tabla[ it ][ itj ];

			if( acum + ans[ it+1 ] < ans[ i ])
				ans[ i ] = acum + ans[ it+1 ];

			tiempo -= arr[ it ].first; it++; itj++;
		}
	}


	cout << ans[ 0 ]/100 << ".";

	if ( ans[ 0 ] % 100 < 10 )
		cout << 0;

	cout << ans[ 0 ] % 100 << endl;
	return 0;
}