#include <bits/stdc++.h>

using namespace std;

int mat[ 9 ][ 9 ];

int main()
{
	int t, n = 9;
	string cad;

	cin >> t;
	while( t-- )
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> cad;
			for (int j = 0; j < n; ++j)
				mat[ i ][ j ] = cad[ j ]-'0';
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
				cout << (mat[ i ][ j ] == 6 ? 2 : mat[ i ][ j ]);
			cout << '\n';
		}
	}
	return 0;
}	