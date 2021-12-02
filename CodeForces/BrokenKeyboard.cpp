#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, pos;
	string cad;
	string ans;
	bitset <28> use;

	cin >> t;
	while( t-- )
	{
		cin >> cad;
		use.reset();
		ans = "";

		pos = 0; n = cad.size();
		while( pos < n )
		{
			if ( pos < n-1 && cad[ pos ] == cad[ pos+1 ] )
				pos += 2;
			else
			{
				if ( !use[ cad[ pos ]-'a' ] )
				{
					ans.push_back( cad[ pos ] );
					use[ cad[ pos ]-'a' ] = true;
					++pos;
				}
			}
		}

		sort( cad.begin(), cad.end() );
		cout << cad << '\n';
	}
	return 0;
}