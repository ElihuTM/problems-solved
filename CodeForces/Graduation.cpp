#include <bits/stdc++.h>
#define maxn 10005

using namespace std;
int n, k, sem, cont;

int sems[ maxn ];
int memo[ maxn ];
vector <int> lista[ maxn ];
int ins[ maxn ];

void dfs( int root )
{
	queue <int> q;
	sems[ root ] = 0;
	for( int i = 0; i < lista[ root ].size(); ++i )
		q.push( lista[ root ][ i ] );

	while( !q.empty() )
	{
		int v = q.front(); q.pop();
		//cout << v << '\n';
		//cout << sem << " y " << sems[ ins[ v ] ] << endl;
		if( sem == sems[ ins[ v ] ] )
		{
			++sem;
			cont = 1;
		}
		else
			++cont;

		sems[ v ] = sem;
		for( int i = 0; i < lista[ v ].size(); ++i )
			q.push( lista[ v ][ i ] );
		
		if( cont == k && !q.empty() )
		{
			++sem;
			cont = 0;
		}
	}
}

int dp( int ro )
{
	if( ~memo[ ro ] )
		return memo[ ro ];

	int ans = 1;
	for( int i = 0; i < lista[ ro ].size(); ++i )
		ans += dp( lista[ ro ][ i ] );
	
	return memo[ n ] = ans;
}

bool fun( int a, int b ) {
	return lista[ a ].size() > lista[ b ].size() || (lista[ a ].size() == lista[ b ].size() && dp( a ) > dp( b ));
}

int main()
{
	memset( memo, -1, sizeof memo );
	memset( ins, -1, sizeof ins );
	int x;
	cin >> n >> k;
	sem = 0, cont = 0;

	for( int i = 1; i <= n; ++i )
	{
		cin >> x;
		lista[ x ].push_back( i );
		ins[ i ] = x;
	}
	
//	vector < pair <int,int> > aux;
	for( int  i = 0; i <= n; ++i )
	{
	//	aux.clear();
	//	for( int j = 0; j < lista[ i ].size(); ++j )
	//		aux[ i ].emplace_back( lista[ lista[ i ][ j ] ].size(), lista[ i ][ j ] );
		
		sort( lista[ i ].begin(), lista[ i ].end(), fun );
	}
	//for( int i = 1; i <= n; ++i )
	//	cout << i << " " << ins[ i ] << endl;
	dfs( 0 );

	cout << sem << '\n';
	return 0;
}
