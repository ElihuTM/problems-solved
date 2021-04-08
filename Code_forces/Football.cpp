#include <bits/stdc++.h>

using namespace std;

int main()
{
	string cad;
	cin >> cad;
	
	int cant = 1;
	for( int i = 1; i < cad.size(); ++i )
	{	
		if( cant > 6 )
		{
			cout << "YES" << '\n';
			return 0;
		}

		if( cad[ i ] == cad[ i-1 ] )
			++cant;
		else
			cant = 0;
	}

	if( cant > 6 )
		cout << "YES" << '\n';
	else
		cout << "NO\n";
	return 0;
}
