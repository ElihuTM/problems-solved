#include <bits/stdc++.h>
#define inf 100000000000L
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;

vvi grid;
vvi dist;
int mvx[] = {1, 0, -1, 0};
int mvy[] = {0, 1, 0, -1};

vi increaseByOne(vi current) {
	for(ll& c: current) {
		c = (c == 9? 1: c+1);
	}
	return current;
}

void getInput() {
	string cad;
	while(cin >> cad) {
		vi current;
		for(char c: cad)
			current.push_back(c - '0');
		
		int n=current.size();
		for(int i=0; i<4; ++i) {
			for(int j=0; j<n; ++j) {
				int value = current[current.size() - n] + 1;
				current.push_back((value == 10 ? 1: value));
			}
		}
		grid.push_back(current);
		dist.push_back(vi(current.size(), inf));
	}
	
	int n=grid.size();
	for(int i=0; i<4; ++i) {
		for(int j=0; j<n; ++j) {
			grid.push_back(increaseByOne(grid[grid.size() - n]));
			dist.push_back(vi(grid.back().size(), inf));
		}
	}
}

bool isPossible(int x, int y, pii front) {
	if(x < 0 || x >= grid.size())
		return false;

	if(y < 0 || y >= grid.size())
		return false;

	return (dist[front.x][front.y] + grid[x][y] < dist[x][y]);
}

ll dijkstra() {
	priority_queue<pii,vpii,greater<pii>> pq;
	dist[0][0] = grid[0][0];

	pq.push({0,0});
	while(!pq.empty()) {
		pii front = pq.top(); pq.pop();
		for(int i=0; i<4; ++i) {
			int x = front.x + mvx[i];
			int y = front.y + mvy[i];

			if(isPossible(x,y,front)) {
				dist[x][y] = dist[front.x][front.y] + grid[x][y];
				pq.push({x,y});
			}
		}
	}

	return dist.back().back();
}

int main() {
	getInput();	
	cout << grid.size() << " " << grid.back().size() << endl;
	cout << dijkstra() << endl;
	return 0;
}
