#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef pair<string, ll> psi;

int main() {
	vector<psi> instructions;
	psi instruction;
	pii ans;
	ll aim = 0;

	while(cin >> instruction.first >> instruction.second)
		instructions.emplace_back(instruction);

	for(const psi& instruction: instructions) {
		if(instruction.first == "forward") {
			ans.second += instruction.second;
			ans.first += aim * instruction.second;	
		}
		else if(instruction.first == "down")
			aim += instruction.second;
		else
			aim -= instruction.second;
	}	
	
	cout << ans.first * ans.second << endl;
	return 0;
}
