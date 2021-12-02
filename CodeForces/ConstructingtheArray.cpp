#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
#define sz(a) s.size()
#define endl '\n'
#define forn(i,n)  for ( int i = 0; i < n; ++i )

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

struct interval
{
	int l, r;
	int len;

	interval ( ) : l(0), r(0), len(0) { }
	interval ( int a, int b ) : l(a), r(b), len(b-a+1) { }

	int mid() {
		if ( len&1 )
			return (l+r) / 2;
		else
			return (l+r-1) / 2;
	}

	bool operator < ( const interval &p ) const
	{
		if ( len < p.len )
			return true;

		if ( len == p.len )
			return l > p.l;

		return false;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	priority_queue <interval> sig;

	ll t, n;
	cin >> t;
	while( t-- )
	{
		cin >> n;
		vi ans( n+1,0 );

		sig.push( interval(1,n) );
		int muv = 1;

		while( muv <= n )
		{
			interval curr = sig.top(); sig.pop();

			ans[ curr.mid() ] = (muv++);

			if ( curr.len == 1 )
				continue;

			if ( curr.len == 2 )
			{
				sig.push( interval( curr.r, curr.r ) );
				continue;
			}

			sig.push( interval(curr.l, curr.mid()-1 ) );
			sig.push( interval(curr.mid()+1, curr.r ) );
		}

		cout << ans[ 1 ];
		for (int i = 2; i <= n; ++i)
			cout  << ' ' << ans[ i ];
		cout << endl;
	}
	
	return 0;
}
