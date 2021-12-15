#include <bits/stdc++.h>

using namespace std;

map<char,int> points;
set<char> open;
set<char> close;

char openBracket(char c) {
	switch(c) {
		case ')': return '(';
		case ']': return '[';
		case '}': return '{';
		case '>': return '<';
	}
	return ')';
}

long long firstCorrupted(string cad) {
	stack<char> last;

	for(char bracket: cad) {
		if(open.find(bracket) != open.end())
			last.push(bracket);
		else {
			if(last.top() == openBracket(bracket))
				last.pop();
			else
				return points[bracket];
		}
	}
	return 0;
}

int main() {
	string cad;
	open = {'(', '[', '{', '<'};
	close = {')', ']', '}', '>'};

	points[')'] = 3;
	points[']'] = 57;
	points['}'] = 1197;
	points['>'] = 25137;
	
	long long ans = 0;
	while(cin >> cad) {
		ans += firstCorrupted(cad);	
	}

	cout << ans << endl;
	return 0;
}
