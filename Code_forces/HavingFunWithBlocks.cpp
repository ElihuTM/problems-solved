#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long ll;

struct matrix
{
	ll a,b,c,d;

	matrix () : a( 1 ), b( 0 ), c( 0 ), d( 1 ) {}
	matrix ( ll _a, ll _b, ll _c, ll _d) : a( _a ), b( _b ), c( _c ), d( _d ) {}

	matrix operator * ( const matrix &p ) const
	{
		matrix ans;
		ans.a = ( ((a * p.a) % mod) + ((b * p.c) % mod ) ) % mod;
		ans.b = ( ((a * p.b) % mod) + ((b * p.d) % mod ) ) % mod;
		ans.c = ( ((c * p.a) % mod) + ((d * p.c) % mod ) ) % mod;
		ans.d = ( ((c * p.b) % mod) + ((d * p.d) % mod ) ) % mod;
		return ans;
	}
};

matrix fast_pow( matrix e, ll x )
{
	matrix ans;
	while( x )
	{
		if ( x&1)
			ans = ans*e;
		
		e = e*e;
		x >>=1;
	}
	return ans;
}

int main()
{
	ll k;
	matrix gen( 3, 8, 1, 3 );
	matrix ans;

	cin >> k;
	ans = fast_pow( gen, k-1 );
	
	ll answer = (((3*ans.c) % mod) + ans.d ) % mod; 
	cout << (answer * answer) % mod << endl;

	return 0;
} 