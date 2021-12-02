#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 100005
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
 
int arr[ maxn ];

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);	

    int t, n, k;
    
    cin >> t;
    while(t--) {

        cin >> n >> k;
        for (int i = 1; i <= n; ++i)
        	cin >> arr[ i ];

        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
        	while( arr[ i ] != i ) {
        		swap( arr[ i ], arr[ arr[ i ] ]);
        		++ans;
        	}
        }

        if (ans > k ) 
            cout << "No" << endl;
        else {
        	k -= ans;
        	if( k&1 )
        		cout << "No" << endl;
        	else
        		cout << "Yes" << endl;
        }
    }
    
    return 0;
}