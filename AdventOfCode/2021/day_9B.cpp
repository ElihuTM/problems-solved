#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
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

bool isValid(int x, int y) {
	if(x < 0 || x >= n)
		return false;

	if(y < 0 || y >= m)
		return false;

	return grid[x][y] != '9';
}

ll floodFill(int xx, int yy) {
	grid[xx][yy] = '9';
	queue<pii> q;
	int ans = 1;
	q.push(make_pair(xx,yy));

	while(!q.empty()) {
		xx = q.front().first;
		yy = q.front().second;
		q.pop();
		for(int i=0; i<4; ++i) {
			int x = xx + mvx[i];
			int y = yy + mvy[i];
			if(isValid(x, y)) {
				++ans;
				q.push(make_pair(x,y));
				grid[x][y] = '9';
			}
		}
	}

	return ans;
}

void getOutput() {
	ll ans = 1;
	vi largest(3);

	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			if(grid[i][j] != '9') {
				ll aux = floodFill(i,j);
				if(aux > largest[0]) {
					largest[0] = aux;
					sort(largest.begin(), largest.end());
				}
			}	
	
	for(ll x: largest)
		ans *= x;
	cout << ans << endl;
}

int main() {
	getInput();
	getOutput();
	return 0;
}
