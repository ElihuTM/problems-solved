#include <bits/stdc++.h>

using namespace std;

vector <string> cad;

bool is_prefix( int a, int b )
{
	if( cad[ a ].size() > cad[ b ].size() )
		return false;

	for( int i = 0; i < cad[ a ].size(); ++i )
		if( cad[ a ][ i ] != cad[ b ][ i ] )
			return false;
	
	return true;
}

int main()
{
	int it = 1;
	string aux;
	bool ex_pref;

	while( cin >> aux )
	{
		cad.clear();
		ex_pref = false;
		while( aux != "9" )
		{
			cad.push_back( aux );
			cin >> aux;
		}

		for( int i = 0; i < cad.size() && !ex_pref; ++i )
			for( int j = 0; j < cad.size() && !ex_pref; ++j )
			{
				if( i != j && is_prefix( i, j ) )
					ex_pref = true;
			}

		if( ex_pref )
			cout << "Set " << it << " is not immediately decodable\n";
		else
			cout << "Set " << it << " is immediately decodable\n";

		++it;
	}
}
