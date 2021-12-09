#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

void increaseReps(vector<vector<int>>& reps, const string& cad) {
	for(int i=0; i<cad.size(); ++i) {
		char number = cad[i] - '0';
		reps[i][number]++;
	}
}

int main() {
	string cad;
	ll length, gamma = 0, epsilon = 0, most_common;

	cin >> cad;

	length = cad.size();
	vector<vector<int>> reps(length, vector<int>(2));
	increaseReps(reps, cad);

	while(cin >> cad)
		increaseReps(reps, cad);

	for(const vector<int>& current: reps) {
		most_common = (current[0] < current[1]);
		gamma = (gamma * 2) + most_common;
		epsilon = (epsilon * 2) + 1 - most_common;
	}

	cout << epsilon * gamma << endl;
	return 0;
}
