#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

vector<int> arrives[2];
int position[2];

bool GetDirection() {
	for(int i=0; i<2; ++i)
		if(position[i] == arrives[i].size())
			return 1-i;

	return (arrives[1][position[1]] < arrives[0][position[0]]);
}

int main() {
	int n, a, direction;

	cin >> n;
	for(int i=0; i<n; ++i) {
		cin >> a >> direction;
		arrives[direction].push_back(a);
	}

	for(int i=0; i<2; ++i) {
		sort(arrives[i].begin(), arrives[i].end());
		position[i] = 0;
	}
	
	int time = 0;
	while(position[0] < arrives[0].size() || position[1] < arrives[1].size()) {
		direction = GetDirection();
		cout << direction << ":"<< endl;
		int& current_position = position[direction];
		const vector<int>& current_arrives = arrives[direction];
		
		time = max(current_arrives[current_position] + 10, time + 10);
		while(current_position < current_arrives.size() && current_arrives[current_position] < time) {
			cout << '\t' << time << " " << current_position << ": " << current_arrives[current_position] << endl;
			time = max(current_arrives[current_position] + 10, time + 10);
			++current_position;
		}
	}
	cout << "Final_positions: " << position[0] << " " << position[1] << endl;
	cout << time << endl;
	return 0;
}
