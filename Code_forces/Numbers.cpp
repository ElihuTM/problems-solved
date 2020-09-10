#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 105
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

ll fact[maxn + 2];
ll rev_fact[maxn + 2];
ll a[ 10 ];

ll n_en_k(int n, int k)
{
    if ( n < k ) return 0LL;

    ll ans= fact[n];
    ans = md( ans*rev_fact[ k ] );
    ans = md( ans*rev_fact[n-k] );
    return ans;
}

ll f_p( ll a, ll n )
{
    ll ans = 1;
    while ( n )
    {
        if ( n&1 )
            ans= md( ans*a );

        a = md( a*a );
        n >>=1;
    }
    return ans;
}

ll mult( ll n, ll sum )
{
	if( sum > n )
		return 0;

	ll ans = 1;
	for (int i = 0; i < 10; ++i)
	{
		ans = md( ans * n_en_k( n, a[ i ] ) );
		n -= a[ i ];
	}

	ans = md( ans * f_p( 10, n ) );
	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	fact[0]=1;
    for (int i=1; i<= maxn; ++i)
        fact[i] = fact[i-1] * i % mod;

    rev_fact[ maxn ]=f_p( fact[maxn] , mod-2 );
    for (int i=maxn-1; i>=0; --i)
        rev_fact[i] = rev_fact[i+1]*(i+1)%mod;

    ll m, sum = 0;
    cin >> m;
    for (int i = 0; i < 10; ++i)
    {
    	cin >> a[ i ];
    	sum += a[ i ];
    }

    ll ans = 0;
    for (int n = 1; n <= m; ++n)
    {
	    for (int i = 1; i < 10; ++i)
	    {
	    	if( a[ i ] > 0 )
	    	{
	    	 	a[ i ]--;
	    		ans = md( ans + mult(n-1, sum-1 ) );
	    		a[ i ]++;
	    	}
	    	else
	    		ans = md( ans + mult(n-1, sum) );
	    }
    }
    cout << ans << endl;
	return 0;
}