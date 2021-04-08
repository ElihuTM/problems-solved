#include <bits/stdc++.h>

using namespace std;
string cad;

bool is_palindrome( int i, int j )
{
	while( i < j )
	{
		if( cad[ i ] != cad[ j ] )
			return false;

		++i;
		--j;
	}

	return true;
}

int main()
{

	cin >> cad;

	for( int i = 0; i < cad.size(); ++i )
	{
		if( is_palindrome( i, cad.size()-1 ) )
		{
			cout << cad;
			for( int j = i-1; j >= 0; --j )
				cout << cad[ j ];
			cout << '\n';
			return 0;
		}
	}

	return 0;
}
