#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q;
	int let[ 27 ];

	string s, t, p;

	cin >> q;
	while( q-- )
	{
		memset( let, 0, sizeof let);
		cin >> s >> t >> p;
	
		for( int i = 0; i < p.size(); ++i )
			++let[ p[ i ] - 'a' ];
		
		bool is_pos = true;
		int it = 0;
		for( int i= 0; i < t.size(); ++i )
		{
			if( it < s.size() && s[ it ] == t[ i ] )
				++it;
			else if( let[ t[ i ] - 'a' ] )
				--let[ t[ i ] - 'a' ];
			else
				is_pos = false;
		}

		if( it == s.size() && is_pos )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
