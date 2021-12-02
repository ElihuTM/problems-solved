#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll t, x, y, a, b, tot, mini;

	cin >> t;
	while( t-- )
	{
		tot = 0;
		cin >> x >> y;
		cin >> a >> b;

		if ( a+a < b )
			tot = a+a;
		else
			tot = b;

		mini =  min( x, y );
		tot *= mini;
		x -= mini;
		y -= mini;
		tot += a*max( x, y );

		cout << tot << '\n';
	}
	return 0;
}