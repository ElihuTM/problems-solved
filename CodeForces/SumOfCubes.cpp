#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define mod(x) (((x%md)+md)%md)
#define maxn 100000
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


ll getSqrt(ll x) {
    ll i = 1, j = 100000, mid;
    if(x == i*i*i || x == j*j*j)
        return (x == i*i*i ? i : j);

    while(j-i > 1) {
        mid = (i+j) / 2;

        if(mid*mid*mid == x)
            return mid;

        if(mid*mid*mid < x)
            i = mid;
        else
            j = mid;
    }
    return mid;
}

string getResult(ll x) {
    ll r1 = 1, r2;

    while(r1*r1*r1 < x) {
        r2 = getSqrt(x - r1*r1*r1);
        if(r2*r2*r2 + r1*r1*r1 == x )
            return "yes";
        
        r1++;
    }

    return "no";
}

int main() {
    int t;
    ll x;

    cin >> t;
    while(t--) {
        cin >> x;
        cout << getResult(x) << endl;
    }
    return 0;
}