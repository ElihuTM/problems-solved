#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod1 1000000007
#define mod2 1000000009
#define base1 29
#define base2 31
#define md1(x) (((x%mod1) + mod1) % mod1)
#define md2(x) (((x%mod2) + mod2) % mod2)
#define maxn 40005
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

string cad;
pii hash_table[ maxn ];
ll exp_base1[ maxn ];
ll exp_base2[ maxn ];
int n, m;

pii get_hash( int begin, int end ) {
	pii answer = hash_table[ end ];
	const ll diference = end - begin + 1;
	const exp1 = exp_base1[ diference ];
	const exp2 = exp_base2[ diference ];

	if( begin == 0 ) return answer;

	answer.ff = md1( answer.ff - md1( hash_table[ begin - 1 ].ff * exp1 ) );
	answer.ss = md2( answer.ss - md2( hash_table[ begin - 1 ].ss * exp2 ) );
	return answer;
}

bool is_possible( int length ) {
	map < pii, int > dictionary;
	pii hash_substring;

	for( int i=length-1; i < n; ++i ) {
		hash_substring = get_hash( i-length+1, i );
		dictionary[ hash_substring ]++

		if( dictionary[ hash_substring ] >= m )
			return true;
	}

	return false;
}

int __upper_bound( int begin, int end ) {
	
	if( m == 1 ) return end;
	if( !is_possible( 1 ) ) return -1;

	int middle, diference = end - begin;

	while( diference > 1 ) {
		middle = begin + ( end - begin ) / 2;

		if( is_possible( middle ) )
			begin = middle;
		else
			end = middle;
	
		middle = end - begin;
	}
	return begin;
}

void build_hash_table( string cad ) {
	hash_table[ 0 ].ff = cad[ 0 ] - 'a';
	hash_table[ 0 ].ss = cad[ 0 ] - 'a';
	n = cad.size();

	for (int i = 1; i < n; ++i) {
		hash_table[ i ].ff = md1( hash_table[ i-1 ].ff*base1 + cad[ i ] - 'a' );
		hash_table[ i ].ss = md2( hash_table[ i-1 ].ss*base2 + cad[ i ] - 'a' );
	}
}

void build_exp ( ) {
	exp_base1[ 0 ] = 1;
	exp_base2[ 0 ] = 1;

	for (int i = 1; i < maxn; ++i) {
		exp_base1[ i ] = md1( exp_base1[ i-1 ] * base1);
		exp_base2[ i ] = md2( exp_base2[ i-1 ] * base2);
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	

	build_exp();

	cin >> m;
	while( m ) {
		cin >> cad;
		build_hash_table( cad );

		const int minimum_size_possible = 1;
		const int maximum_size_possible = cad.size();
		const int maximum_length = __upper_bound( minimum_size_possible, maximum_size_possible );

		cout << maximum_length << endl;
		cin >> m;
	}

	return 0;
}
