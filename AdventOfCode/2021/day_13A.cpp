#include <bits/stdc++.h>
#define maxn 1400

using namespace std;
typedef pair<bool,int> pii;
typedef vector<pii> vpii;

vpii cuts;
bool paper[maxn][maxn];
int n = maxn, m = maxn;

void getCut(string cad) {
	cad[1] = ' ';
	char axis;
	int coord;

	stringstream ss(cad);
	ss >> axis >> coord;

	cuts.emplace_back(axis == 'x', coord);
}

void getPoint(string cad) {
	int x, y;
	for(char& letter: cad)
		if(letter == ',')
			letter = ' ';

	stringstream ss(cad);
	ss >> x >> y;
	paper[y][x] = true;

}

void getInput() {
	memset(paper,false,sizeof(paper));
	string cad, aux1, aux2;

	while(cin >> cad) {
		if(cad == "fold")
			break;
		getPoint(cad);
	}

	cin >> aux1 >> cad;
	getCut(cad);
	while(cin >> aux1 >> aux2 >> cad)
		getCut(cad);
}

void foldInstruction(pii instruction) {
	if(instruction.first) {
		m = instruction.second;
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				paper[i][m-j-1] |= paper[i][m+j+1];
	} else {
		n = instruction.second;
		for(int i=0; i<m; ++i) 
			for(int j=0; j<n; ++j)
				paper[n-j-1][i] |= paper[n+j+1][i];
	}
}

int main() {
	pii aux;
	getInput();
	
	for(pii cut:cuts)
		foldInstruction(cut);
	
	for(int i=0; i<n; ++i) {
		for(int j=0; j<m; ++j)
			cout << (paper[i][j] ? '#' : '.');
		cout << endl;
	}
	return 0;
}
