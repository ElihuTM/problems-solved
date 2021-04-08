#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int t, k, muv;
	ll ans, r, uno = 1;

	cin >> t;
	while( t-- )
	{
		cin >> r >> k;

		if ( k & 1)
		{
			muv = (k>>1) ;

			ans = (uno << muv)*r*r;
			cout << ans << "PI\n";
		}
		else
		{
			muv = (k>>1) + 1;
			cout << (uno << muv)*r*r << endl;
		}
	}
	return 0;
}