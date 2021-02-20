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
    int t, n, num;
    vi remainder;

    cin >> t;
    while(t--) {
        cin >> n;
        remainder.assign(3,0);
        for(int i=0; i<n; ++i) {
            cin >> num;
            remainder[num%3]++;
        }

        int ans = 0;
        for(int j=0; j<3; ++j)
            for(int i=0; i<3; ++i)
                if(remainder[i] > n/3) {
                    remainder[(i+1)%3] += remainder[i] - n/3;
                    ans += remainder[i] - n/3;
                    remainder[i] = n/3;
                }

        cout << ans << endl;
    }
    return 0;
}