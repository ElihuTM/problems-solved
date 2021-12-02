#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
	string cad;
	cin >> cad;
	int n = cad.size();
	bool is_pos = false;

	for (int i = 0; i < n; ++i)
		if ( cad[ i ] == '8' || cad[ i ] == '0' )
		{
			cout << "YES\n";
			cout << cad[ i ] << endl;
			return 0;
		}


	for (int i = 0; i < n; ++i)
		for (int j = i+1; j < n; ++j)
			if ( ((cad[ i ] - '0') * 10 + cad[ j ] -'0') % 8 == 0 )
			{
				cout << "YES\n";
				cout << cad[ i ]<<cad[ j ] << endl;
				return 0;
			}

	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			for (int k = j+1; k < n; ++k)
			{
				if ( ((cad[ i ] - '0') * 100 + (cad[ j ] -'0') * 10 + cad[ k ] - '0' ) % 8 == 0 )
				{
					cout << "YES\n";
					cout << cad[ i ]<<cad[ j ]<<cad[ k ] << endl;
					return 0;
				}
			}
		}
	}

	cout << "NO\n";
	return 0;
}