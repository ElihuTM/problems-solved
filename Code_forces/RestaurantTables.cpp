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

ll fact[maxn + 2];
ll rev_fact[maxn + 2];

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
	
	ll n, a, b, c = 0, d, ans=0;
    cin >> n >> a >> b;

    for (int i = 0; i < n; ++i)
    {
        cin >> d;
        if( d == 1 )
        {
            if( a > 0 )
                --a;
            else if( b > 0 )
            {
                --b;
                ++c;
            }
            else if( c > 0 )
                --c;
            else
                ++ans;
        }
        else
        {
            if ( b > 0)
                --b;
            else
                ans += 2;
        }
    }

    cout << ans << endl;
	return 0;
}