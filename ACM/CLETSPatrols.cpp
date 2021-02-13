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
typedef vector<ld> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

vvi prob;
vvi memo;

int main() {
    int n, m;
    cin >> n >> m;

    prob = vvi(n, vi(n));
    memo = vvi(m, vi(n));
    for(int i=0; i<n; i++)
        for(int j=0; j<n; ++j)
            cin >> prob[i][j];

    for(int i=0; i<n; ++i)
        memo[0][i] = prob[0][i];

    for(int i=1; i<m; ++i)
        for(int j=0; j<n; ++j)
            for(int k=0; k<n; ++k)
                memo[i][k] += memo[i-1][j] * prob[j][k];

    for(int i=0; i<n; ++i)
        cout << memo[m-1][i] << endl;

    return 0;
}