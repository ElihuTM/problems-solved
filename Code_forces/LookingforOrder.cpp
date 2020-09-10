#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn (1<<24)
#define md(x) (((x%mod) + mod) % mod)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) a.size()
#define endl '\n'
#define inf 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

struct point
{
	ll x, y;

	ll dist( point a ){
		return (a.x - x)*(a.x - x) + (a.y - y)*(a.y - y);
	}
};

vector<point> arr;
ll memo[ maxn ];
point center;
ll n, ans;
vi path;

ll dp( ll mask )
{
	if( mask == 0 )
		return 0;

	if(  ~memo[ mask ] )
		return memo[ mask ];

	ll p;
	for (int i = 0; i < n; ++i)
		if( (mask & (1<<i)) ) { p = i; break; }

	mask ^= (1<<p);
	ll better = center.dist( arr[ p ] ) + dp( mask );
	for (int i = 0; i < n; ++i)
	{
		int qmask = (1 << i);
		if( (mask & qmask) )
		{
			mask ^= qmask;
			better = min( better, arr[ p ].dist( arr[ i ] ) + dp( mask ) );
			mask |= qmask;
		}
	}

	mask |= (1 << p);
	return memo[ mask ] = better;
}

void reconstruir ( int mask )
{
	if( mask == 0 )
		return;

	int p, q;
	for (int i = 0; i < n; ++i)
	{
		if( mask & (1<<i) )
		{
			p = i;
			break;
		}
	}

	mask ^= (1 << p);
	ll better = inf, aux;
	for (int i = 0; i < n; ++i)
	{
		int qmask = (1<<i);
		if( mask & qmask )
		{
			mask ^= qmask;
			aux = arr[ p ].dist( arr[ i ] ) + dp( mask );

			//cout << mask << endl;
			//for (int i = 0; i < 10; ++i)
			//	cout << ((mask&(1<<i)) != 0);
			//cout << endl;	
			//cout << p+1 << " " << i+1 << " " << arr[ p ].dist( arr[ i ]) << " " << dp( mask )  << " " << aux <<endl;
			
			mask |= qmask;

			if( aux < better )
			{
				q = i;
				better = aux;
			}
		}
	}

	if( center.dist( arr[ p ] ) + dp( mask ) < better )
	{
		path.p_b( p+1 );
		path.p_b( 0 );
	}
	else
	{
		path.p_b( p+1 );
		path.p_b( q+1 );
		path.p_b( 0 );
		mask ^= (1 << q );
	}

	reconstruir( mask );

}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	

	ll mask, ans = 0, better, aux;

	cin >> center.x >> center.y;
	cin >> n;
	
	arr.resize( n );
	mask = (1<<n)-1;
	memset( memo, -1, sizeof(memo) );

	for (int i = 0; i < n; ++i) {
		cin >> arr[ i ].x >> arr[ i ].y;
		ans += center.dist( arr[ i ] );
	}

	//cout << dp( mask ) << endl;

	ans += dp( mask );
	reconstruir( mask );

	cout << ans << endl << 0;
	for (int i = 0; i < sz( path ); ++i)
		cout << ' ' << path[ i ];
	cout << endl;
	
	return 0;
}