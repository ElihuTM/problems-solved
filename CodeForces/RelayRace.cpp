#include <bits/stdc++.h>
#define x first
#define y second
#define inf 1000000007LL
#define maxn 305
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair <ll,ll> pii;

unordered_map< ll, ll > memo;
ll mat[ maxn ][ maxn ];
pii ok, aux;
ll n;

ll make_hash( pii p, pii q )
{
    long long ans = 0LL;
    ans = ans*1000 + p.x;
    ans = ans*1000 + p.y;
    ans = ans*1000 + q.x;
    ans = ans*1000 + q.y;

    return ans;
}

ll dp( pii p, pii q )
{
    if( p > q )
    {
        aux = p;
        p = q;
        q = aux;
    }

    if( p == ok && q == ok )
        return mat[ n-1 ][ n-1 ];

    if( p.x < 0 || p.x >= n || p.y < 0 || p.y >= n )
        return -inf;
    
    if( q.x < 0 || q.x >= n || q.y < 0 || q.y >= n )
        return -inf;

    unordered_map < ll, ll >::const_iterator got = memo.find( make_hash( p,q ) );
    if( got != memo.end() )
        return got->second;

    ll ans;
    pii p1( p.x+1, p.y );
    pii p2( p.x, p.y+1 );
    pii q1( q.x+1, q.y );
    pii q2( q.x, q.y+1 );

    if( p == q )
        ans = mat[ p.x ][ p. y ];
    else
        ans = mat[ p.x ][ p.y ] + mat[ q.x ][ q.y ];

    ll ans2 = max( dp( p1, q1 ), dp( p1, q2 ) );
    if( p != q)
        ans2 = max( ans2, dp( p2, q1 ) );
    ans2 = max( ans2, dp( p2, q2 ) );

    ans += ans2;

    memo.insert( make_pair( make_hash(p,q), ans ) );
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
    cin >> n;
    ok = pii( n-1, n-1 );
    for( int i = 0; i < n; ++i )
        for (int j = 0; j < n; ++j )
            cin >> mat[ i ][ j ];

    ll ans = dp( pii( 0,0 ), pii( 0,0) );
    cout << ans << endl;
	return 0;
}