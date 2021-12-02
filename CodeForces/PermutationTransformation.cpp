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

vi arbol;
vi depth;
vi arr;

int getMax(int i, int j) {
    pii ans(-1,-1);

    while(i <= j) {
        if(arr[i] > ans.ff)
            ans = pii(arr[i], i);
        ++i;
    }
    return ans.ss;
}

void fill(int value, int i, int j) {
    if(i > j)
        return;

    int root = getMax(i,j);
    depth[root] = value;

    fill(value + 1, i, root-1);
    fill(value + 1, root + 1, j);
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        arbol.resize(n);
        depth.resize(n);
        arr.resize(n);

        for(int i=0; i<n; ++i)
            cin >> arr[i];

        fill(0, 0, n-1);
        for(int i=0; i<n; ++i)
            cout << depth[i] << ' ';
        cout << endl;
    }
    return 0;
}