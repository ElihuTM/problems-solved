#include <bits/stdc++.h>

using namespace std;

int ans( int disct, int same, int n )
{
	if ( n < 2 )
		return 0;

	if ( same == 1)
		return 1;

	int aux = min( disct, same-1 );
	int aux2 = min( disct-1, same );

	return max( aux, aux2 );
}

int main()
{
	int t, n, a;
	map<int, int> mayor;
	set<int> distintos;
	pair<int, int> aux;

	cin >> t;
	while( t-- )
	{
		cin >> n;

		mayor.clear();
		distintos.clear();
		aux = make_pair( 0, 0 );

		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			mayor[ a ]++;
			distintos.insert( a );

			if( mayor[ a ] > aux.second )
				aux = make_pair( a, mayor[ a ] );
		}

		cout << ans( distintos.size(), aux.second, n ) << '\n';
	}
	return 0;
}	