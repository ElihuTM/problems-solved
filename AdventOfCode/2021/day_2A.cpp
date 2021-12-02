#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<pair<string, int>> instructions;
	pair<string, int> instruction;
	pair<int,int> ans;

	while(cin >> instruction.first >> instruction.second)
		instructions.emplace_back(instruction);

	for(const pair<string, int>& instruction: instructions) {
		if(instruction.first == "forward")
			ans.second += instruction.second;
		else if(instruction.first == "down")
			ans.first += instruction.second;
		else
			ans.first -= instruction.second;
	}	
	
	cout << ans.first * ans.second << endl;
	return 0;
}
