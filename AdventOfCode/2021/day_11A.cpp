#include <bits/stdc++.h>

using namespace std;

int mvx[] = {1,1,0,-1,-1,-1,0,1};
int mvy[] = {0,1,1,1,0,-1,-1,-1};
int grid[10][10];
bool visited[10][10];

bool isPossible(int x, int y) {
	if(x < 0 || x > 9)
		return false;

	if(y < 0 || y > 9)
		return false;
	return true;
}

bool areZero() {
	for(int i=0; i<10; ++i)
		for(int j=0; j<10; ++j)
			if(grid[i][j])
				return false;

	return true;
}

void mark(int xx, int yy) {
	if(visited[xx][yy] || grid[xx][yy] < 10)
		return;
	
	visited[xx][yy] = true;
	for(int i=0; i<8; ++i) {
		int x = xx + mvx[i];
		int y = yy + mvy[i];
		if(isPossible(x,y)) {
			grid[x][y]++;
			mark(x,y);
		}
	}
}

int increaseByOne() {
	int ans = 0;
	memset(visited, false, sizeof(visited));

	for(int i=0; i<10; ++i)
		for(int j=0; j<10; ++j)
			grid[i][j]++;

	for(int i=0;i<10; ++i)
		for(int j=0; j<10; ++j)
			mark(i,j);

	for(int i=0; i<10; ++i)
		for(int j=0; j<10; ++j)
			if(grid[i][j] > 9) {
				grid[i][j] = 0;
				ans++;
			}

	return ans;
}

int main() {
	long long ans = 0, steps = 0;
	string line;
	for(int i=0; i<10; ++i) {
		cin >> line;
		for(int j=0; j<10; ++j)
			grid[i][j] = line[j] - '0';
	}

	while(!areZero()) {
		increaseByOne();
		++steps;
	}
	
	cout << steps << endl;
	return 0;
}
