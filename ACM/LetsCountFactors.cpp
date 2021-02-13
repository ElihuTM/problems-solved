#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define mod(x) (((x%md)+md)%md)
#define maxn 10000002
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

ll criba[maxn];

void llenar() {
    for(int i=0; i<maxn; ++i)
        criba[ i ] = i;
    criba[0] = 1;

    for(int i=4; i<maxn; i+=2)
        criba[i] = 2;

    for(ll i=3; i<maxn; i+=2)
        if(criba[i] == i)
            for(ll j=i*i; j<maxn; j+=i)
                criba[j] = min(criba[j], i);
}

unordered_set<ll> primes;

int main() {
    llenar();

    ll n, a, b;
    cin >> n;
    while(n--) {
        primes.clear();
        cin >> a >> b;

        while(a != 1) {
            primes.insert( criba[a] );
            a /= criba[a];
        }

        while(b != 1) {
            primes.insert( criba[b] );
            b /= criba[b];
        }

        cout << primes.size() << endl;
    }

    return 0;
}