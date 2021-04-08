#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector< ll > vi;

ll f_p( ll x, int exp )
{
	ll ans = 1;
	while( exp )
	{
		if( exp&1 )
			ans *= x;

		x *= x;
		exp >>= 1;
	}
	return ans;
}

int main()
{
	string cad1, cad2;
	ll ans, aux;
	vi c, x;

	while( getline( cin, cad1 ) )
	{
		getline( cin, cad2 );
		c.clear();
		x.clear();

		stringstream ss1, ss2;
		ss1 << cad1;
		ss2 << cad2;

		while( ss1 >> aux )
			c.push_back( aux );

		while( ss2 >> aux )
			x.push_back( aux );

		for( int i = 0; i < x.size(); ++i )
		{
			ans = 0;
			ll xx = 1;
			for( int j = c.size()-1; j >= 0; --j )
			{
				ans += c[ j ]*xx;
				xx *= x[ i ];
			}

			cout << ans;
			if( i < x.size()-1 )
				cout << " ";
		}
		cout << '\n';
	}
}
