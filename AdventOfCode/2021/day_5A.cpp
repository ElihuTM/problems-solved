#include <bits/stdc++.h>
#define maxn 1000
#define x first
#define y second

using namespace std;
typedef pair<int,int> point;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef pair<point, point> line;

vector<line> lines;
int grid[maxn][maxn];

void getInput() {
	lines.clear();
	memset(grid, 0, sizeof(grid));

	line current;
	string cad;
	char aux;

	while(getline(cin, cad)) {
		for(char& letter: cad)
			if(letter == ',')
				letter = ' ';
		stringstream ss(cad);

		while(ss >> current.x.x) {
			ss >> current.x.y;
			ss >> aux; ss >> aux;
			ss >> current.y.x; ss >> current.y.y;
			
			lines.push_back(current);
		}
	}
}

void moveTo(pii& current, const pii& target) {
	if(current.x < target.x)
		current.x++;
	else if(current.x > target.x)
		current.x--;

	if(current.y < target.y)
		current.y++;
	else if(current.y > target.y)
		current.y--;
}

void getOutput() {
	for(line current: lines) {
			for(point i=current.x; i!=current.y; moveTo(i, current.y))
				grid[i.x][i.y]++;

			grid[current.y.x][current.y.y]++;
	}

	int ans = 0;
	for(int i=0; i<maxn; ++i)
		for(int j=0; j<maxn; ++j)
			if(grid[i][j] > 1)
				ans++;

	cout << ans << endl;
}

int main() {
	getInput();	
	getOutput();
	return 0;
}
