#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;
	bool gr;
	string str, a, b;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		cin >> str;

		a = "";
		b = "";
		gr = false;

		for (int i = 0; i < n; ++i)
		{
			if ( str[ i ] == '1' )
			{
				if ( gr )
				{
					a.push_back( '0' );
					b.push_back( '1' );
				}
				else
				{
					a.push_back( '1' );
					b.push_back( '0' );
					gr = true;
				}
			}
			else
			{
				if ( gr )
				{
					a.push_back( '0' );
					b.push_back( str[ i ] );
				}
				else
				{
					a.push_back( ( ( str[ i ] - '0') / 2 ) + '0' );
					b.push_back( ( ( str[ i ] - '0') / 2 ) + '0' );
				}
			}
		}

		cout << a << '\n' << b << '\n';
	}
	return 0;
}