#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
//#define mod(x) (((x%md)+md)%md)
#define maxn 200005
#define p_b(a) push_back(a)
#define all(a) a.begin(), a.end()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<ll> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

ll fact[maxn + 10];
ll revfact[maxn + 10];

ll f_p(ll x, ll n, ll m)
{
    ll res = 1;
    while(n)
    {
        if(n&1)
            res = res * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return res;
}

void fill()
{
    fact[0] = 1;
    for(ll i = 1; i <= maxn; i++)
        fact[i] = (fact[i-1] * i) % mod;
    revfact[maxn-1] = f_p(fact[maxn], mod-2,mod) * maxn % mod;

    for(ll i = maxn - 2; i > 0; i--)
        revfact[i] = (revfact[i+1] * (ll)(i+1)) % mod;

}

ll nCk(ll n,ll k)
{
    if( n < k) return 0;
    if (n == 0 or k == n) return 1;
    return (fact[n] * revfact[k] % mod) * revfact[n-k]  % mod;
}

int main()
{
    fill();
    ll t, n;

    cin >> t;
    while(t--) {
        cin >> n;
        if(n==1)
            cout << 1 << endl;
        else
            cout << nCk(n+n-1, n-1) << endl;
    }

}