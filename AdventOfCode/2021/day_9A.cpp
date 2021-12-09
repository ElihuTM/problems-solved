#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

vector<string> grid;
int n, m;
int mvx[] = {0, 1, 0, -1};
int mvy[] = {1, 0, -1, 0};

void getInput() {
	string cad;
	while(cin >> cad) {
		grid.push_back(cad);
	}
	m = grid.front().size();
	n = grid.size();
}

bool isLowerThan(int i, int j, int k) {
	int x = i + mvx[k];
	int y = j + mvy[k];

	if(x < 0 || x >= n)
		return true;

	if(y < 0 || y >= m)
		return true;

	return grid[i][j] < grid[x][y];
}

void getOutput() {
	ll ans = 0;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j) {
			bool isLower = true;
			for(int k=0; k<4; ++k)
				isLower = (isLower && isLowerThan(i,j,k));

			if(isLower)
				ans += grid[i][j] - '0' + 1;
		}
	cout << ans << endl;
}

int main() {
	getInput();
	getOutput();
	return 0;
}
