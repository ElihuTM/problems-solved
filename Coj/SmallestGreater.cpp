#include <iostream>
#define endl '\n'

using namespace std;
typedef long long ll;

#define OK ((ll)1<<51)-1L

inline ll LSOne( ll n )
{
	return n & (-n);
}

inline int cont_bits( ll x )
{
	int ans = 0;
	while( x )
	{
		++ans;
		x -= LSOne( x );
	}

	return ans;
}

inline ll last_cero( ll x )
{
	ll _x = (~x)&OK;

	ll n = LSOne( _x );
	if ( n > x )
		return n;

	n = 1;
	n <<= 51;
	while( n > x )
		n >>= 1;

	while( x&n )
		n >>= 1;

	return n;
}

inline ll nivela( ll x, int k )
{
	ll n = 1;
	int cont = 0;

	while( n <= x )
		n <<= 1;

	ll it = (n>>1);
	--n;

	while( cont < k )
	{
		++cont;
		it >>= 1;
	}

	it <<= 1; --it;
	return n - it;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	ll m;
	int k, cont;

	while( cin >> m >> k )
	{
		cont = cont_bits( m );

		if ( cont > k)
		{
			cout << m << endl;
			continue;
		}

		if ( cont == k )
		{
			cout << nivela( m, k ) << endl;
			continue;
		}

		while( cont < k )
		{
			//cout << '\t' << last_cero( m );
			m += last_cero( m );
			//cout << '\t' << m << endl;
			++cont;
		}

		cout << m << endl;
	}

	return 0;
}