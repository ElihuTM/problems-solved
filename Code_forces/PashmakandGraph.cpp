#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 100005
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
 
struct ari {
	int a, b, d, num;
 
	ari( ){a = b = d = num = 0; }
	ari( int y, int z, int w ) : b( y ), d( z ), num( w ) { }

	bool operator < ( const ari p ) const {
		return d < p.d;
	}
};
 
vector< vector<ari> > lista;
vector<ari> aris;
ari aux( 0, 0, 0 );
vi memo;
 
int dp( int ari_u )
{
	if( ~memo[ ari_u ] )
		return memo[ ari_u ];
 
	int ans = 0;
	int b = aris[ ari_u ].b;
 	aux.d = aris[ ari_u ].d;

 	int ini = (upper_bound( all( lista[ b ] ), aux ) - lista[ b ].begin() );
	
	for (int i = ini; i < lista[ b ].size(); ++i)
		ans = max( ans, dp( lista[ b ][ i ].num ) );
 
	return memo[ ari_u ] = ans + 1;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int n, m, a, b, c;
	cin >> n >> m;
 
	lista.resize( n );
	aris.resize( m );
	memo.assign( m, -1 );

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;

		lista[ a-1 ].push_back( ari( b-1, c, i ) );
		aris[ i ] = ari( b-1, c, i );
	}

	for (int i = 0; i < n; ++i)
		sort( all( lista[ i ] ) );

	int ans = 0;
	for ( int i = 0; i < m; ++i )
		ans = max( ans, dp( i ) );
 
	cout << ans << endl;
	return 0;
}