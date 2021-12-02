#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 1000005
#define md(x) (((x%mod) + mod) % mod)
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

bitset <maxn> criba;
int prime_numbers[ maxn ];

void llenar() {
	criba.set();
	criba[ 0 ] = criba[ 1 ] = false;

	for (int i = 4; i < maxn; i+=2)
		criba[ i ] = false;

	for ( ll i = 3; i < maxn; i+=2 )
		if( criba[ i  ] )
			for (ll j = i*i; j < maxn; j+=i )
				criba[ j ] = false;
}

bool is_pos( int ini, int fin, int x, int value ) {
	for ( int i = ini+x-1; i <= fin; ++i)
		if( prime_numbers[ i ] - prime_numbers[ i-x ] < value )
			return false;

	return true;
}

int binary_search( int a, int b, int value ) {
	if( prime_numbers[ b ] - prime_numbers[ a-1 ] < value )
		return -1;

	int m, i = 0, j = b-a+1;
	while( j-i > 1 ) {
		m = i + (j-i) / 2;

		//cout << m << " " << is_pos( a, b, m, value ) << endl;
		if( is_pos( a, b, m, value ) )
			j = m;
		else
			i = m;
	}
	return j;
}

int main()
{
	int a, b, k;
	llenar();
	prime_numbers[ 0 ] = 0;
	for (int i = 1; i < maxn; ++i)
		prime_numbers[ i ] = prime_numbers[ i-1 ] + criba[ i ];

	scanf("%d%d%d", &a, &b, &k);
	int ans = binary_search( a, b, k );
	printf("%d\n", ans);

	return 0;
}