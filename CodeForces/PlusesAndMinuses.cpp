#include <bits/stdc++.h>

using namespace std;

bool all_minus( string cad )
{
	for( int i=0; i<cad.size(); ++i )
		if( cad[ i ] != '-' )
			return false;
	return true;
}

long long gauss( long long n ) {
	return ( n*(n+1) )/2 + n;
}

int main()
{
	int t;
	string cad;
	cin >> t;

	while( t-- )
	{
		cin >> cad;

		if( all_minus( cad ) )
			cout << gauss( cad.size() ) << '\n';
		else
		{
			long long ans, ant, aux, cont;
			ans = ant = aux = cont = 0;

			for( int i=0; i<cad.size(); ++i )
			{
				++cont;
				if( cad[ i ] == '+' )
					aux++;
				else
					aux--;

				if( aux < 0 )
				{
					ans += cont+ant;
					ant = cont+ant;
					aux = 0;
					cont = 0;
				}
			}
			ans += cont+ant;

			cout << ans << '\n';
		}
	}
	return 0;
}
