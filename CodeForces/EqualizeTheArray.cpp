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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, n, a;
    cin >> t;
    while(t--) {
        cin >> n;

        map<int, int> reps;
        map<int,int> counter;

        for(int i=0; i<n; ++i) {
            cin >> a;
            reps[a]++;
        }
        for(auto c: reps)
            counter[c.ss]++;

        vpii arr;
        arr.emplace_back(0,0);
        for(auto c: counter)
            arr.push_back(c);

        vi acum(arr.size());
        acum[0] = 0;
        for(int i=1; i<arr.size(); ++i)
            acum[i] = acum[i-1] + arr[i].ff*arr[i].ss;

        ll ans = n+n, past = 0;
        for(int i=arr.size()-1; i>0; --i) {
            ans = min(ans, acum[i-1]+past);

            past += (arr[i].ff - arr[i-1].ff) * arr[i].ss;
            arr[i-1].ss += arr[i].ss;
        }
        cout << ans << endl;
    }
    return 0;
}