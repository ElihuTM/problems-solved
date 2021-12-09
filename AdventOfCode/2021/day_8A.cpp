#include <bits/stdc++.h>

using namespace std;

struct entry {
	vector<string> patterns;
	vector<string> digits;

	entry(string input) {
		stringstream ss(input);
		for(int i=0; i<10; ++i) {
			ss >> input;
			patterns.push_back(input);
		}
		ss >> input;
		for(int i=0; i<4; ++i) {
			ss >> input;
			digits.push_back(input);
		}
	}

	int getReps() {
		int ans = 0;
		for(string digit: digits) {
			int size = digit.size();
			if(size == 2 || size == 3 || size == 4 || size == 7)
				++ans;
		}
		return ans;
	}	
};

vector<entry> entries;

void getInput() {
	string cad;
	while(getline(cin,cad))
		entries.emplace_back(cad);
}

void getOutput() {
	int ans = 0;
	for(entry ent: entries)
		ans += ent.getReps();
	cout << ans << endl;
}

int main() {
	getInput();
	getOutput();
	return 0;
}
