#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll memo[ 65 ][ 1000005 ];
string cad;
int n;

ll dp( int pos, int ant )
{
	if ( pos == n )	return 1;

	if ( ~memo[ pos ][ ant ] )	return memo[ pos ][ ant ];

	ll aux = 0, ans = 0;
	for (int i = pos; i < n; ++i)
	{
		aux = (aux * 10) + cad[ i ] - '0';
		
		if( aux < ant || aux  == 0)	continue;
		if( aux > 1000000 ) break;

		ans += dp( i+1, aux );
	}

	return memo[ pos ][ ant] = ans;
}

int main()
{
	memset( memo, -1, sizeof memo );
	cin >> cad;
	n = cad.size();

	cout << dp(0,0) << '\n';
	return 0;
}