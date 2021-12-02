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
    cin >> t;
    while(t--) {
        cin >> n;

        set<int> ans;
        vpii arr(n);
        vi acum(n);

        for(int i=0; i<n; ++i) {
            cin >> arr[i].ff;
            arr[i].ss = i;
        }
        sort(all(arr));

        acum[0] = arr[0].ff;
        for(int i=1; i<n; ++i)
            acum[i] = acum[i-1] + arr[i].ff;

        ans.insert(arr.back().ss);
        for(int i=n-2; i>=0; --i) {
            if(acum[i] >= arr[i+1].ff && ans.find(arr[i+1].ss) != ans.end() )
                ans.insert(arr[i].ss);
        }

        cout << ans.size() << endl;
        for(auto c: ans)
            cout << c + 1 << ' ';
        cout << endl;
    }
    return 0;
}