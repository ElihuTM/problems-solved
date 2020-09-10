#include <bits/stdc++.h>
#define maxn 107

using namespace std;

char mat[ maxn ][ maxn ];

int main()
{
	int t, n, m;
	cin >> t;

	while( t-- )
	{
		cin >> n >> m;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				mat[ i ][ j ] = 'B';

		mat[ 0 ][ 0 ] = 'W';
		if ( n > 2)
			mat[ 1 ][ 0 ] = 'W';

		if ( m > 2)
			mat[ 0 ][ 1 ] = 'W';

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
				cout << mat[ i ][ j ];
			cout << endl;
		}
	}

	return 0;
}	