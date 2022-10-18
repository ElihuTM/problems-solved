#include <iostream>
#include <cstring>
#include <vector>

#define maxn 1005
#define maxw 35

using namespace std;

int memo[maxn][maxw];
int prices[maxn];
int weights[maxn];
int n, g;

int dp(int pos, int w) {
	if(w < 0 )
		return -maxn;

	if(pos == n)
		return 0;

	if(memo[pos][w] != -1)
		return memo[pos][w];

	return memo[pos][w] = max(
		dp(pos+1, w),
		dp(pos+1, w-weights[pos]) + prices[pos]
	);
}

int main() {
	int t, weight, ans;
	cin >> t;

	while(t--) {
		memset(memo, -1, sizeof(memo));
		ans = 0;

		cin >> n;	
		for(int i=0; i<n; ++i) {
			cin >> prices[i] >> weights[i];	
		}

		cin >> g;
		while(g--) {
			cin >> weight;
			ans += dp(0, weight);
		}
		cout << ans << endl;
	}
	return 0;
}
