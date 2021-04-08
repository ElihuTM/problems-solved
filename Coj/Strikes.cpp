#include <bits/stdc++.h>
#define maxn 500007

using namespace std;

vector<int> Lista[ maxn ];
int num_hijos[ maxn ];
int padre[ maxn ];
bool vivo[ maxn ];
queue <int> s;

inline void bfs( int nodo, int dad )
{
	int front;
	padre[ nodo ] = dad;
	vivo[ nodo ] = true;
	s.push( nodo );

	while( !s.empty() )
	{
		front = s.front(); s.pop();
		num_hijos[ front ] = Lista[ front ].size() - 1;

		for ( int &v: Lista[ front ])
			if ( !vivo[ v ] )
			{
				vivo[ front ] = true;
				padre[ v ] = front;
				s.push( v );
			}
	}
	vivo[ 0 ] = false;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, q, x, a, b, aux, ans = 1;
	cin >> n;

	Lista[ 0 ].push_back( 1 );
	Lista[ 1 ].push_back( 0 );
	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b;
		Lista[ a ].push_back( b );
		Lista[ b ].push_back( a );
	}

	bfs( 0, -1 );

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> x;
		if ( x > 0 )
		{
			vivo[ x ] = false;
			num_hijos[ padre[ x ] ]--;

			ans += (vivo[ padre[ x ] ] + num_hijos[ x ] - 1);
		}
		else
		{
			x = -x;
			vivo[ x ] = true;
			num_hijos[ padre[ x ] ]++;

			ans -= (vivo[ padre[ x ] ] + num_hijos[ x ] - 1);
		}
		cout << ans << "\n";
	}

	return 0;
}