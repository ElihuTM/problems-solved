#include <bits/stdc++.h>
#define maxn 100005

using namespace std;
typedef long long ll;

bitset <maxn> criba;
bitset <maxn> is_amic;
int ans[ maxn ];
vector <ll> p;

ll f_p( int x, int exp )
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

int sumDiv( ll n )
{
	ll pp = 2, cont = 0, exp, ans = 1;
	
	while( pp*pp <= n )
	{
		exp = 0;
		while( n%pp == 0 )
		{
			++exp;
			n /= pp;
		}

		ans *= ( f_p( pp, exp+1 ) - 1) / (pp-1);
		pp = p[ ++cont ];
	}

	if( n != 1 )
		ans *= ( n*n - 1 ) / ( n-1 );

	return ans;
}

void llena()
{
	criba.set();

	criba[ 0 ] = criba[ 1 ] = 0;
	for( int i=4; i < maxn; i+=2 )
		criba[ i ] = false;
	
	p.push_back( 2 );
	for( ll i = 3; i < maxn ; i +=2 )
		if( criba[ i ] )
		{
			p.push_back( i );
			for( ll j = i*i; j < maxn; j += i)
				criba[ j ] = false;
		}
}

int main()
{
	llena();
	is_amic.reset();
	int t, a, n;

	cin >> t;
	for( int i = 2; i < maxn; ++i )
	{
		if( !is_amic[ i ] && !criba[ i ] )
		{
			a = sumDiv( i )-i;
			//cout << i << " : " << a << endl;
			if( i != a && sumDiv( a )-a  == i )
			{
				is_amic[ i ] = true;
				is_amic[ a ] = true;
			}
		}
	}

	ans[ 0 ] = 0;
	for( int i = 1; i < maxn; ++i )
	{
		ans[ i ] = ans[ i-1 ];
		if( is_amic[ i ] )
			ans[ i ] += i;
	}

	while( t-- )
	{
		cin >> n;
		cout << ans[ n ] << '\n';
	}

	return 0;
}
