#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int b, h, r1, r2;

	cin >> b >> h >> r1 >> r2;
	while( b || h || r1 || r2 )
	{
		int x = b - r1 - r2;
		int y = h - r1 - r2;

		if( x < 0 || y < 0 || r1+r1 > min( b, h ) || r2+r2 > min( b, h ) )
			cout << "N\n";
		else
		{
			int hip = (x*x) + (y*y);

			if(  hip  >= (r1+r2)*(r1+r2) )
				cout << "S\n";
			else
				cout << "N\n";
		}

		cin >> b >> h >> r1 >> r2;
	}
	return 0;
}
