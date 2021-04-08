#include <bits/stdc++.h>
#define forn(i,n) for( int i = 0; i < n; ++i )
#define maxn 105

using namespace std;

string cad1, cad2;
string dic[ maxn ];
map <string, int> mdic;
int padres[ maxn ];
vector <int> lista[ maxn ];
priority_queue < int, vector <int>, greater<int> > q;

void limpia()
{
	forn(i,maxn)
	{
		lista[ i ].clear();
		padres[ i ] = 0;
	}
	mdic.clear();
}

int main()
{
	int n, m, qw = 0;
	while( cin >> n )
	{

		limpia();
		forn(i,n)
		{
			cin >> cad1;
			mdic[ cad1 ] = i;
			dic[ i ] = cad1;
		}
		
		cin >> m;
		forn( i, m )
		{
			cin >> cad1 >> cad2;
			++padres[ mdic[ cad2 ] ];
			lista[ mdic[ cad1 ] ].push_back( mdic[ cad2 ] );
		}

		forn(i,n)
			if( padres[ i ] == 0 )
				q.push( i );
		
		cout << "Case #" << ++qw << ": Dilbert should drink beverages in this order:";
		while( !q.empty() )
		{
			int u = q.top(); q.pop();
			cout << " " << dic[ u ];

			forn(i,lista[u].size())
			{
				int v = lista[ u ][ i ];
				--padres[ v ];

				if( padres[ v ] == 0 )
					q.push( v );
			}
		}
		cout << ".\n\n";
	}

}
