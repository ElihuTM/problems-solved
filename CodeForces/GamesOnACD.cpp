#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod2 1000000009L
#define mod1 1000000021L
#define b2 31L
#define b1 37L
#define md1(x) (((x%mod1) + mod1) % mod1)
#define md2(x) (((x%mod2) + mod2) % mod2)
#define maxn 100005
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

map< pii, int> dictionary;
vpii hash_table;
ll pot_b1;
ll pot_b2;
int n, k;

ll fast_pow( ll x, ll exp, ll modulo ) {
	ll ans = 1;
	while( exp ) {
		if( exp&1 )
			ans = (ans * x ) % modulo;
	
		exp >>= 1;
		x = (x * x) %  modulo;
	}
	return ans;
}

pii make_hash( string cad ) {
	pii ans( 0, 0 );
	for( int i=0; i < cad.size(); ++i ) {
		ans.ff = md1( md1(ans.ff*b1) + cad[ i ] - 'a' );
		ans.ss = md2( md2(ans.ss*b2) + cad[ i ] - 'a' );
	}
	return ans;
}

pii get_hash( int a, int b ) {
	pii ans = hash_table[ b ];

	if( a == 0 ) return ans;

	ans.ff = md1( ans.ff - md1(hash_table[ a-1 ].ff*pot_b1) );
	ans.ss = md2( ans.ss - md2(hash_table[ a-1 ].ss*pot_b2) );
	return ans;
}

bool is_possible( int current ) {

	set< pii > exist;
	for( int i = current; i < current+n; i += k ) {
		pii game = get_hash( i, k+i-1 );
		if( dictionary.find( game ) == dictionary.end() or exist.find( game ) != exist.end() )
			return false;

		exist.insert( game );
	}

	return true;
}

void imp( int current ) {
	cout << "YES" << endl;
	for( int i = current; i < current+n; i += k ) {
		pii game = get_hash( i, k+i-1 );
		cout << dictionary[ game ];

		if( i+k < current+n )
			cout << " ";
	}
	cout << endl;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	string cad, aux;
	cin >> n >> k;
	cin >> cad;

	n = cad.size();
	cad += cad;

	pot_b1 = fast_pow( b1, k, mod1 );
	pot_b2 = fast_pow( b2, k, mod2 );

	hash_table.resize( 2*n );
	hash_table[ 0 ] = make_hash( cad.substr( 0,1 ) );
	for (int i = 1; i < hash_table.size(); ++i)
	{
		hash_table[ i ].ff = md1( md1( hash_table[ i-1 ].ff*b1 ) + cad[ i ] - 'a');
		hash_table[ i ].ss = md2( md2( hash_table[ i-1 ].ss*b2 ) + cad[ i ] - 'a');
	}

	int q;
	cin >> q;
	for (int i = 1; i <= q; ++i)
	{
		cin >> aux;
		dictionary[ make_hash( aux ) ] = i;
	}

	for (int i = 0; i < k; ++i)
		if( is_possible( i ) )
		{
			imp( i );
			return 0;
		}

	cout << "NO" << endl;
	return 0;
}