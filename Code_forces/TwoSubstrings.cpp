#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

bitset <maxn> izq;
bitset <maxn> der; 

int main()
{
	string cad;
	izq.reset();
	der.reset();

	cin >> cad;
	int len = cad.size();
	for (int i = 1; i < len; ++i)
	{
		if ( (cad[ i-1 ] == 'B' && cad[ i ] == 'A') || izq[ i-1 ] )
			izq[ i ] = true;

		if ( (cad[ len-i ] == 'A' && cad[ len-i-1 ] == 'B') || der[ len-i ] )
			der[ len-i-1 ] = true;
	}

	for (int i = 0; i < len-1; ++i)
	{
		if ( cad[ i ] == 'A' && cad[ i+1 ] == 'B' )
		{
			bool l = (i == 0 ? false : izq[ i-1 ]);
			bool r = (i >= len-2 ? false : der[ i+2 ]);

			if ( l|r )
			{
				cout << "YES\n";
				return 0;
			}
		}
	}

	cout << "NO\n";
	return 0;
}