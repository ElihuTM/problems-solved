#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int caso, ans;
	int b, p, f, h, c;
	cin >> caso;

	while( caso-- )
	{
		ans = 0;
		cin >> b >> p >> f;
		cin >> h >> c;

		if( h > c )
		{
			if( b/2 >= p )
			{
				ans += p*h;
				b -= 2*p;

				ans += ( b/2 >= f ? f*c : (b/2)*c );
			}
			else
				ans += (b/2) * h;
		}
		else
		{
			if( b/2 >= f )
			{
				ans += f*c;
				b -= 2*f;

				ans += ( b/2 >= p ? p*h : (b/2)*h );
			}
			else
				ans += (b/2) * c;
		}

		cout << ans << '\n';
	}
	return 0;
}
