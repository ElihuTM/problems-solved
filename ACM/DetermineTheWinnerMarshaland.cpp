#include <bits/stdc++.h>
#define mod 1000000007
#define maxn 1000007

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
        criba[i] = i;
    criba[0] = 1;

    for(int i=4; i<maxn; i+=2)
        criba[i] = 2;

    for(ll i=3; i<maxn; i+=2)
        if(criba[i] != i)
            for(ll j=i*i; j<maxn; j+=i)
                criba[j] = min(criba[j], i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    llenar();
    int t, k;
    
    cin >> t;
    while(t--) {
        unordered_set<ll> fact_primos;
        cin >> k;
        k+=2;

        while(k != 1) {
            fact_primos.insert(criba[k]);
            k /= criba[k];
        }

        fact_primos.erase(2);
        if(fact_primos.empty())
            cout << -1 << endl;
        else {
            for(auto c: fact_primos)
                cout << c << ' ';
            cout << endl;
        }
    }
    return 0;
}