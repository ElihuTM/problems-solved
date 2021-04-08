#include <bits/stdc++.h>
#define inf 999999999
#define maxn 103

using namespace std;
typedef vector <int> vi;

int residuo[ maxn ][ maxn ];
vi anterior;
int f, s;

void augment_path( int nodo, int maxEdge )
{
	if ( nodo == s )
	{
		f = maxEdge;
		return;
	}

	int ant = anterior[ nodo ];
	if ( ~ant )
	{
		augment_path( ant, min(maxEdge, residuo[ ant ][ nodo ] ) );
		residuo[ ant ][ nodo ] -= f;
		residuo[ nodo ][ ant ] += f;
	}
}

int main()
{
	int n, m, t, a, b, c, mf, it = 0;
	vi dist;
	cin >> n;

	while( n )
	{
		cin >> s >> t >> m; --s; --t;

		mf = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				residuo[ i ][ j ] = 0;

		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c; --a; --b;
			residuo[ a ][ b ] += c;
			residuo[ b ][ a ] += c;
		}

		while(1)
		{
			f = 0;
			anterior.assign( n, -1 );
			dist.assign( n, inf );
			queue <int> next;
			next.push( s );

			while( !next.empty() )
			{
				int u = next.front(); next.pop();

				//if ( u == t ) break;

				for (int v = 0; v < n; ++v)
					if ( residuo[ u ][ v ] > 0 && dist[ v ] == inf )
					{
						dist[ v ] = dist[ u ] + 1;
						anterior[ v ] = u;
						next.push( v );
					}
			}

			augment_path( t, inf );
			if( !f ) break;
			mf += f;
		}
		cout << "Network " << ++it << "\nThe bandwidth is " << mf << ".\n\n";
		cin >> n;
	}
	return 0;
}