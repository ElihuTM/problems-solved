
#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	int a, b, c, aa, bb, ans;

	cin >> a >> b >> c;

	aa = a%c; bb = b%c;

	if ( aa + bb < c)
		ans = 0;
	else
		if ( aa < bb )
			ans = c - bb;
		else
			ans = c - aa;

	cout << (a+b)/c << " " << ans << '\n';	
	
	return 0;
}