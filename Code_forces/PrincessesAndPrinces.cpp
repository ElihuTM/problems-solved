#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
	int t, n, k, s, princesa;
	bool exist;

	vi lista;
	set<int> principe;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		
		principe.clear();
		princesa = -1;

		for (int i = 0; i < n; ++i)
			principe.insert( i );

		for (int u = 0; u < n; ++u)
		{
			lista.clear();
			cin >> k;

			for (int j = 0; j < k; ++j)
			{
				cin >> s; --s;
				lista.push_back( s );
			}

			exist = false;
			for (int i = 0; i < lista.size(); ++i)
			{
				int v = lista[ i ];
				if ( principe.find( v ) != principe.end() )
				{
					principe.erase( v );
					exist = true;
					break;
				}
			}

			if ( !exist && princesa == -1)
				princesa = u+1;
		}

		if ( principe.empty() )
			cout << "OPTIMAL\n";
		else
		{
			cout << "IMPROVE\n";
			cout << princesa << ' ' << (*principe.begin())+1 << '\n';
		}
	}
	return 0;
}
	