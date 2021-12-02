#include <bits/stdc++.h>
#define maxn 100000

using namespace std;

int main()
{
	int t, x, y;
	cin >> t;
	while( t-- )
	{
		cin >> x >> y;

		if ( x == 1)
		{
			if( y == 1 )
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if ( x <= 3 )
		{
			if( y <= 3 )
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
			cout << "YES\n";
	}
	return 0;	
}