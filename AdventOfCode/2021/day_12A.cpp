#include <bits/stdc++.h>

using namespace std;

map<string,vector<string>> adjList;
set<string> visited;
long long ans;

void getInput() {
	ans = 0;
	string cad, a, b;
	while(cin >> cad) {
		for(char& letter: cad)
			if(letter == '-')
				letter = ' ';

		stringstream ss(cad);
		ss >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
}

void moveTo(string current, bool canDuplicate) {
	if(current == "end") {
		++ans;
		return;
	}	

	for(string cad: adjList[current]) {
		if(isupper(cad[0]) || visited.find(cad) == visited.end()) {
			visited.insert(cad);
			moveTo(cad, canDuplicate);
			visited.erase(cad);
		} else if(canDuplicate && cad != "start") {
			moveTo(cad, false);
		}
	}
}

int main() {
	getInput();	
	
	visited.insert("start");
	moveTo("start", true);

	cout << ans << endl;
	return 0;
}
