#include <bits/stdc++.h>
#define mod1 1000000007
#define mod2 1000000087
#define b1 31
#define b2 29
#define endl '\n'
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef pair< ll, ll> pii;
typedef vector< pii > vpii;

ll fast_pow( ll x, ll exp, ll mod )
{
	ll ans = 1;
	while( exp )
	{
		if( exp&1 )
			ans = (ans * x) % mod;

		x = ( x * x ) % mod;
		exp >>= 1;
	}

	return ans;
}

pii mult( pii aux, ll exp, char a )
{
	aux.ff = ( (aux.ff * fast_pow( b1, exp, mod1 ) % mod1 ) + a - 'a') % mod1;
	aux.ss = ( (aux.ss * fast_pow( b2, exp, mod2 ) % mod2 ) + a - 'a') % mod2;

	return aux;
}

struct hashing
{
	string str;
	vpii arr;
	int len;

	hashing( ) { }
	hashing( string cad )
	{
		str = cad;
		len = str.size();
		arr = vpii( len );

		arr[ 0 ] = pii( str[ 0 ] - 'a', str[ 0 ] - 'a' );
		for (int i = 1; i < len; ++i)
			arr[ i ] = mult( arr[ i-1 ], 1 , str[ i ] );
	}

	pii get_substr( int i, int j ) {
		if ( i == 0 )
			return arr[ j ];

		pii aux = arr[ j ];
		pii aux2 = mult( arr[ i-1 ], j-i+1, 'a' );

		aux.ff -= aux2.ff;
		aux.ss -= aux2.ss;
		aux.ff = (aux.ff + mod1 ) % mod1;
		aux.ss = (aux.ss + mod2 ) % mod2;

		return aux;
	}
};

bool is_pal( string &str )
{
	int i = 0, j = str.size()-1;

	while( j > i )
	{
		if( str[ i ] != str[ j ] )
			return false;
		++i; --j;
	}

	return true;
}

string get_preffix( string &str )
{
	string ans;
	int i = 0, j = str.size()-1;

	while( j > i )
	{
		if ( str[ i ] != str[ j ] )
			break;

		ans.push_back( str[ i ] );
		++i; --j;
	}

	return ans;
}

string get_max_pal( hashing h1, hashing h2 )
{
	int len = h1.len;
	string ans1, ans2;

	for (int i = 0; i < len; ++i)
		if ( h1.get_substr( i, len-1 ) == h2.get_substr( 0, len-i-1 ) )
		{
			ans1 = h1.str.substr( i, len-i ); 		
			break;
		}

	for (int i = len-1; i >= 0 ; --i)
		if ( h1.get_substr( 0, i ) == h2.get_substr( len-i-1, len-1 ) )
		{
			ans2 = h1.str.substr( 0, i+1 );
			break;
		}

	if ( ans2.size() >= ans1.size() )
		return ans2;
	
	return ans1;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int t, len, ini;
	string str, rstr, preffix, suffix;

	cin >> t;
	while( t-- )
	{
		cin >> str;
		len = str.size();

		if( is_pal( str ) )
			cout << str << endl;
		else
		{
			preffix = get_preffix( str );
			suffix = preffix;

			ini = preffix.size();  
			str = str.substr( ini, len - 2*ini );

			rstr = str;
			reverse( rstr.begin(), rstr.end() );
			reverse( suffix.begin( ), suffix.end( ) );
			hashing h1( str );
			hashing h2( rstr );

			str = get_max_pal( h1, h2 );

			cout << preffix << str << suffix << endl;
		}
	}
	return 0;
}