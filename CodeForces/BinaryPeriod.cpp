#include <bits/stdc++.h>

using namespace std;

bool all_equals( string &cad )
{
	for (int i = 1; i < cad.size(); ++i)
		if ( cad[ i ] != cad[ i-1 ])
			return false;
	return true;
}

char rev( char x )
{
	if ( x == '0')
		return '1';
	
	return '0';
}

int main()
{
	int t;
	string cad;

	cin >> t;
	while( t-- )
	{
		cin >> cad;

		if ( all_equals( cad ) )
			cout << cad << '\n';
		else
		{
			string ans;
			ans.push_back( cad[ 0 ] );
			for (int i = 1; i < cad.size(); ++i)
			{
				if ( cad[ i ] == cad[ i-1 ] )
					ans.push_back( rev( cad[ i ] ) );
				ans.push_back( cad[ i ] );
			}

			cout << ans << '\n';
		}
	}
	return 0;
}