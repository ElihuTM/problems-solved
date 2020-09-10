#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

vvi lista;
int n, m;

vi bfs (int u )
{
	queue <int> q;
	vi dist( n, -1 );
	dist[ u ] = 0;

	q.push( u );
	while( !q.empty() )
	{
		int v;
		u = q.front(); q.pop();
		
		for (int i = 0; i < lista[ u ].size(); ++i)
		{
			v = lista[ u ][ i ];
			if ( dist[ v ] == -1 )
			{
				dist[ v ] = dist[ u ] + 1;
				q.push( v );
			}	
		}
	}

	return dist;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	int a, b;
	cin >> n >> m;

	lista.resize( n );
	vi team( m );

	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b; --a; --b;
		lista[ a ].push_back( b );
		lista[ b ].push_back( a );
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> team[ i ];
		team[ i ]--;
	}

	vi dist1 = bfs( team[ 0 ] );

	int nodo, deep = -1;
	for (int i = 0; i < m; ++i)
	{
		int v = team[ i ];
		if ( dist1[ v ] > deep )
		{
			deep = dist1[ v ];
			nodo = v;
		}
	}

	vi dist2 = bfs( nodo );

	int mid = -1;
	for (int i = 0; i < n; ++i)
		if ( dist1[ i ] == dist2[ i ] && dist1[ i ] == deep / 2 )
		{
			mid = i;
			break;
		}

	
	if ( mid == -1 )
	{
		cout << "NO\n";
		return 0;
	}

	vi dist3 = bfs( mid );

	int val = dist3[ team[ 0 ] ];
	for (int i = 0; i < m; ++i)
		if ( dist3[ team[ i ] ] != val )
		{
			cout << "NO\n";
			return 0;
		}

	cout << "YES\n";
	cout << mid+1 << endl;
		
	return 0;
}
