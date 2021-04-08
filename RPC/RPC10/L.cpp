#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod1 1000000007
#define mod2 1000000003
#define b1 17
#define b2 13

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

string cad;
int n;

/*
pii gen_hash( int dig )
{
	
	pii ans = make_pair( 0, 0 );
	for( int i = 0; i < dig; ++i )
	{
		ans.ff = ((( ans.ff * b1 ) % mod1) + cad[ i ] - '0' + 1 ) % mod1;
		ans.ss = ((( ans.ss * b2 ) % mod2) + cad[ i ] - '0' + 1 ) % mod2;
	}
	return ans;
}*/

string imp( int dig, ll x )
{
	string ans;
	for( int i = 0; i < dig; ++i )
		ans.push_back( '0' );

	for( int i = ans.size()-1; x; --i )
		ans[ i ] = (x%10) + '0';

	return ans;
}

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


ll roll_hash( int ini, int fin )
{
	ll ans = 0;
	for( int i = ini; i < fin; ++i )
		ans = ans * 10 + cad[ i ] - '0';
	//pii ans = aux;
	
	//ans.ff = (((( ans.ff - ( cad[ i-dig ]*b1_a_la[ dig ] ) + mod1 ) % mod1 ) * b1 ) + cad[ i ] - '0' + 1 ) % mod1;
	//ans.ss = (((( ans.ss - ( cad[ i-dig ]*b2_a_la[ dig ] ) + mod2 ) % mod2 ) * b2 ) + cad[ i ] - '0' + 1 ) % mod2;

	return ans;
}

bool is_pos( int dig )
{
	set <ll> dic;

	//string aux = gen_hash( dig );
	//dic.insert( aux );

	for( int i = 0; i < n-dig; ++i )
		cout << roll_hash
		dic.insert( roll_hash( i, i+dig ) );
	
	if( dic.size() < f_p( 10, dig ) )
	{
		cout << dig << " ";

		ll it = 0;
		for( auto &c: dic )
		{
			if( c > it )
			{
				cout << imp( it, dig );
				break;
			}

			++it;
		}
	}

	return (dic.size() < f_p( 10, dig )); 
}

int main()
{
	int t;
	/*
	b1_a_la[ 0 ] = b2_a_la[ 0 ] = 1;
	for( int i = 1; i <= 5; ++i )
	{
		b1_a_la[ i ] = ( b1_a_la[ i-1 ] * b1 ) % mod1;
		b2_a_la[ i ] = ( b2_a_la[ i-1 ] * b2 ) % mod2;
	}*/

	cin >> t;

	while( t-- )
	{
		cin >> n >> cad;
		for( int i = 1; i <= n; ++i )
			if( is_pos( i ) )
				break;
	}
	return 0;
}
