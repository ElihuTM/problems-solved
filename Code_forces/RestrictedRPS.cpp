#include <bits/stdc++.h>
#define maxn 103

using namespace std;
char arr[ maxn ];

int main()
{
	map<char, int> el;
	map<char, char> ant;

	ant[ 'R' ] = 'P';
	ant[ 'P' ] = 'S';
	ant[ 'S' ] = 'R';
	int t,n,x;
	char dato;

	cin >> t;
	while( t-- )
	{
		int cont = 0;
		cin >> n;

		for (int i = 0; i < n; ++i)
			arr[ i ] = 'N';

		cin >> x; el[ 'R' ] = x;
		cin >> x; el[ 'P' ] = x;
		cin >> x; el[ 'S' ] = x;
		
		for (int i = 0; i < n; ++i)
		{
			cin >> dato;
			if ( el[ ant[ dato ] ] > 0)
			{
				el[ ant[ dato ] ]--;
				arr[ i ] = ant[ dato ];
				++cont;
			}
		}

		if( cont >= ceil( (double)n/2.0) )
		{
			cout << "YES\n";
			for (int i = 0; i < n; ++i)
			{
				if ( arr[ i ] != 'N' )
					cout << arr[ i ];
				else if( el[ 'R' ] > 0)
				{
					cout << 'R';
					el[ 'R' ]--;
				}
				else if( el[ 'P' ] > 0)
				{
					cout << 'P';
					el[ 'P' ]--;
				}
				else if( el[ 'S' ] > 0)
				{
					cout << 'S';
					el[ 'S' ]--;
				}
			}
			cout << '\n';
		}
		else
			cout << "NO\n";
	}
	return 0;
}