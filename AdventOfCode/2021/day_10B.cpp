#include <bits/stdc++.h>

using namespace std;

map<char,char> reverseBracket;
map<char,int> points;
set<char> open;

vector<long long> answers;

void completeSequences(const string& sequence) {
	stack<char> last;
	for(char bracket: sequence) {
		if(open.find(bracket) != open.end())
			last.push(bracket);
		else {
			if(last.top() == reverseBracket[bracket])
				last.pop();
			else
				return;
		}
	}

	long long ans = 0;
	while(!last.empty()) {
		ans = ans * 5 + points[reverseBracket[last.top()]];
		last.pop();	
	}

	answers.push_back(ans);
}

int main() {
	open = {'(', '[', '{', '<'};	
	points = {
		{')',1}, {']',2},
		{'}',3}, {'>',4}};
	reverseBracket = {
		{'{','}'}, {'[',']'},
		{'(',')'}, {'<','>'}};
	for(auto bracket: reverseBracket)
		reverseBracket[bracket.second] = bracket.first;

	string cad;	
	while(cin >> cad)
		completeSequences(cad);	
	sort(answers.begin(), answers.end());

	cout << answers[answers.size() / 2] << endl;
	return 0;
}
