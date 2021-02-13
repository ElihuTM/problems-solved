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

int main() {
    int n,m;
    cin >> n >> m;
    ll a = (1L << (n-1)) -1;
    ll b = (1L << (m-1)) -1;
    cout << 2*(a+b+1) << endl;

    return 0;
}