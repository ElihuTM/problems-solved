#include <bits/stdc++.h>
#define maxn 100005
#define p_b(a) push_back(a)

using namespace std;
typedef long long ll;

bitset <maxn> criba;
bitset <maxn> is_a;
vector <ll> p;

void llena()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = 0;

	for( int i = 4; i < maxn; i+=2)
		criba[ i ] = false;
	
	p.p_b(2);
	for( ll i = 3; i < maxn; i += 2 )
		if( criba[ i ] )
		{
			for( ll j = i*i; j < maxn; j += i )
				criba[ j ] = false;
			p.p_b(i);
		}
}

ll f_p( ll x, int exp )
{
	ll ans = 1;
	while( exp )
	{
		if( exp&1 )
			ans *= x;

		x *= x;
		exp >>=1;
	}
	return ans;
}

bool is_abundant( ll n )
{
	ll cop = n;
	ll pp = 2, cont = 0, exp, ans = 1;

	while( pp*pp <= n )
	{
		exp = 0;
		while( n%pp == 0 )
		{
			++exp;
			n /= pp;
		}

		ans *= (f_p( pp, exp+1 ) - 1) / ( pp-1 );
		pp = p[ ++cont ];
	}

	if( n != 1 )
		ans *= ( n*n - 1 ) / ( n-1 );

	return ans-cop > cop;
}

int main()
{
	llena();
	for( int i = 0; i < maxn; ++i )
		if( is_abundant( i ) )
			is_a[ i ] = true;

	int t, n;
	bool ban;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		ban = false;
		for( int i = 1; i <= n/2; ++i )
			if( is_a[ i ] && is_a[ n-i ] )
			{
				ban = true;
				break;
			}
		
		if( ban )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
