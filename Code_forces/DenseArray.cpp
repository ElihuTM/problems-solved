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
    int t, n;
    vi num;

    cin >> t;
    while(t--) {
        cin >> n;
        num.resize(n);
        for(int i=0; i<n; ++i)
            cin >> num[i];

        int ans = 0;
        for(int i=1; i<n; ++i) {
            int mini = min(num[i], num[i-1]);
            int maxi = max(num[i], num[i-1]);
        
            while(2*mini < maxi) {
                ++ans;
                mini *= 2;
            }
        }

        cout << ans << endl;
    }
    return 0;
}