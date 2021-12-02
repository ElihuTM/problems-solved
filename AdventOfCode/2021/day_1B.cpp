#include<iostream>
#include<vector>

using namespace std;

int main() {
	int depth, answer = 0;
	vector<int> depths;

	while(cin >> depth)
		depths.emplace_back(depth);

	for(int i=1; i<depths.size()-2; ++i) 
		if(depths[i+2] > depths[i-1])
			++answer;

	cout << answer << endl;
	return 0;
}
