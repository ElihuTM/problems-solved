#include <bits/stdc++.h>
#define ff first
#define ss second
#define inf 1000000007
#define maxn 106
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

int res[ maxn ][ maxn ], mf, f, s, t;
vi p;

void augment( int v, int minEdge ) {
	if( v == s ) {
		f = minEdge;
		return;
	}
	else if( p[ v ] != -1 ) { 
		augment( p[ v ], min( minEdge, res[ p[ v ]][ v ]) ); 
		res[ p[ v ]][ v ] -= f;
		res[ v ][ p[ v ]] += f;
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n, q, op, a, b, k;
	cin >> n >> q;

	vi up( n+2, n );
	vi bottom( n+2, 1);

	while( q-- )
	{	
		cin >> op >> a >> b >> k;
		if( op == 1 ) {
			for (int i = a; i <= b; ++i)
				bottom[ i ] = max( bottom[ i ], (ll)k );
		}
		else {
			for (int i = a; i <= b; ++i)
				up[ i ] = min( up[ i ], (ll)k );
		}
	}

	s = 0;
	t = 2*n + 2;
	for ( int i = 1; i <= n; ++i)
	{
		for (int j = bottom[ i ]; j <= up[ i ]; ++j)
		{
			res[ i+n ][ j ] += n;
			res[ j ][ i+n ] += n;
			//cout << i+n << " " << j << endl;
		}
		res[ s ][ i+n ] = 1;

		//cout << s << " " << i+n << endl;
		//cout << i << " " << t << endl;
	}

	ll ans = 0;
	ll cont = 0;
	ll paso = 1;
	ll last = 0;

	vi answer( n+2, 0);

	mf = 0;
	while( cont < n )
	{		
		for (int i = 1; i <= n; ++i)
			res[ i ][ t ]++;

		while( 1 )
		{
			f = 0;
			vi dist( maxn, inf ); dist[ s ] = 0;
			queue <int> q; q.push( s );
			p.assign( maxn, -1 );
			while( !q.empty() ){
				int u = q.front(); q.pop();
				if( u == t ) break;
				for( int v = 0; v < maxn; v++ )
					if( res[ u ][ v ] > 0 && dist[ v ] == inf )
						dist[ v ] = dist[ u ] + 1, q.push( v ), p[ v ] = u;
			}

			augment( t, inf );
			if( f == 0 ) break;

			mf += f;
		}

		if( mf == last )
		{
			cout << -1 << endl;
			return 0;
		}

		last = mf;
		cont = mf;
		/*if( paso == 1 )
			answer[ paso ] = mf;
		else
		{
			ll dif = mf - answer[ paso-1 ];
			answer[ paso ] = 2*dif;
			answer[ paso-1 ] -= dif;
		}*/
		++paso;
	}

	for (int i = 1; i <= n; ++i)
	{
		//cout << i << " " << res[ t ][ i ] << endl;
		ans += res[ t ][ i ]*res[ t ][ i ];
	}
	
	cout << ans << endl;
	return 0;
}