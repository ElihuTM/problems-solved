#include <bits/stdc++.h>
#define maxn 3000

using namespace std;

bool input[maxn][maxn];
bool output[maxn][maxn];
bool current;
string decoder;

bool get(int x, int y) {
	if(x < 0 || x >= maxn)
		return current;

	if(y < 0 || y >= maxn)
		return current;

	return input[x][y];
}

int getPosition(int x, int y) {
	int value = 0;
	for(int i=-1; i<2; ++i)
		for(int j=-1; j<2; ++j)
			value = value*2 + get(x+i, y+j);
	return value;
}

void getOutput() {
	for(int i=0; i<maxn; ++i) {
		for(int j=0; j<maxn; ++j) {
			int position = getPosition(i, j);
			output[i][j] = (decoder[position] == '#');
		}
	}
}

int main() {
	string cad;
	current = false;
	memset(input, false, sizeof(input));
	cin >> decoder;

	int x = 1450, y = 1450;
	while(cin >> cad) {
		for(int i=0; i<cad.size(); ++i)
			input[x][y + i] = (cad[i] == '#');
		++x;
	}
	
	int steps = 50;
	while(steps--) {
		cout << steps << endl;
		getOutput();
		swap(input,output);
		current = 1 - current;
	}
		
	int ans = 0;
	for(int i=0; i<maxn; ++i)
		for(int j=0; j<maxn; ++j)
			ans += input[i][j];

	cout << ans << endl;
	return 0;
}
