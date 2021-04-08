//4037
#include <bits/stdc++.h>
#define maxn 50005
#define inf 1000000000000L

using namespace std;
typedef long long ll;
typedef pair <ll, int > pii;

int p[ 3 ], n, m;
vector< pii > Lista[ maxn ]; 

void Dijkstra( int root, ll* dist)
{
	priority_queue< pii, vector<pii>, greater<pii> > pq;
	for (int i = 0; i < n+2; ++i)
		dist[ i ] = inf;
	dist[ root ] = 0;

	pq.push( pii( 0,root ) );
	pii aux;

	while( !pq.empty() )
	{
		aux = pq.top(); pq.pop();
		int u = aux.second;
		ll d = aux.first;

		if ( d > dist[ u ])
			continue;

		for ( pii &v: Lista[ u ] )
			if ( dist[ u ] + v.first < dist[ v.second ] )
			{
				dist[ v.second ] = dist[u] + v.first;
				pq.push( pii(dist[v.second],v.second) );
			}
	}
}

ll _Dijkstra( ll* root, ll* p1, ll* p2, ll* p3 )
{
	for (int i = 0; i < n; ++i)
	{
		Lista[ n ].emplace_back( root[ i ] + p1[ i ], i );
		Lista[ i ].emplace_back( p2[ i ] + p3[ i ], n+1 );
	}

	ll answer[ n+3 ];
	Dijkstra( n, answer );

	for (int i = 0; i < n; ++i)
		Lista[ i ].pop_back();
	Lista[ n ].clear();

	return answer[ n+1 ];
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	int a, b;
	ll c;
	
	cin >> n >> m;
	ll distP[ 4 ][ maxn ];
	for (int i = 0; i < 3; ++i)
	{
		cin >> p[ i ]; p[i]--;
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c; a--; b--;
		Lista[ a ].emplace_back( c,b );
		Lista[ b ].emplace_back( c,a );
	}

	Dijkstra( 0, distP[ 3 ] );
	for (int i = 0; i < 3; ++i)
		Dijkstra( p[ i ], distP[ i ] );

	ll ans = inf, aux;
	for (int i = 0; i < 3; ++i)
	{
		aux = _Dijkstra(distP[ 3 ], distP[ i ], distP[ (i+1)%3 ], distP[ (i+2)%3 ]);
		if( ans > aux )
			ans = aux;
	}

	cout << ans << endl;
	return 0;
}