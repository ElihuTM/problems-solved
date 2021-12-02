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
vi p;

void llenar()
{
    criba.set();
    criba[ 0 ] = criba[ 1 ] = false;

    for (int i = 4; i < maxn; i+=2)
        criba[ i ] = false;
    p.push_back( 2 );

    for ( ll i = 3; i < maxn; i+=2)
        if( criba[ i ] )
        {
            for ( ll j = i*i; j < maxn; j+=i )
                criba[ j ] = false;
            p.push_back( i );
        }
}

ll factorizar( ll n )
{
    ll pp = 2, pos = 0, cont = 0;
    while( pp*pp <= n )
    {
        if( n % pp == 0 )
            ++cont;

        while( n % pp == 0 )
            n /= pp;

        pp = p[ ++pos ];
    }

    if( n != 1 )
        ++cont;

    return cont;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);    
        
    ll n;

    llenar();
    cin >> n;

    for( ll i = 1; i <= 1000000; ++i )
    {
        if( n % (i*i) == 0 )
        {
            ll num = n / (i*i);
            ll factores = factorizar( num );

            if( factores == 1 )
            {
                cout << "YES" << endl;
                return 0;
            }

        }
    }

    cout << "NO" << endl;
    return 0;
}