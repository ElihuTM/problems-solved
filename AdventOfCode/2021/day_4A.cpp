#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;

vi getNumbers(string& cad) {
	for(char& letter: cad)
		if(letter == ',')
			letter = ' ';
	
	vi numbers;
	ll number;
	stringstream ss(cad);

	while(ss >> number)
		numbers.push_back(number);

	return numbers;
}

void mark(vvi& board, int number) {
	for(int i=0; i<5; ++i)
		for(int j=0; j<5; ++j)
			if(board[i][j] == number)
				board[i][j] = -1;
}

bool won(vvi board) {
	for(int i=0; i<5; ++i) {
		bool inRaw = true;
		bool inCol = true;
		for(int j=0; j<5; ++j) {
			if(board[i][j] != -1)
				inRaw = false;
			if(board[j][i] != -1)
				inCol = false;
		}

		if(inRaw || inCol)
			return true;
	}

	return false;
}

ll countPoints(vvi board) {
	ll ans = 0;
	for(int i=0; i<5; ++i)
		for(int j=0; j<5; ++j)
			if(board[i][j] != -1)
				ans += board[i][j];

	return ans;
}
bool someWon(ll number, vector<vvi>& boards, ll& answer) {
	for(vvi& board: boards) {
		mark(board, number);
		if(won(board)) {
			answer = countPoints(board);
			return true;
		}
	}
	return false;
}

int main() {
	string stringNumbers;
	getline(cin, stringNumbers);

	vi numbers = getNumbers(stringNumbers);
	vector<vvi> boards;
	vvi current(5, vi(5));
	ll newNumber;
	
	while(cin >> newNumber) {
		current[0][0] = newNumber;
		for(int i=1; i<5; ++i)
			cin >> current[0][i];

		for(int i=1; i<5; ++i)
			for(int j=0; j<5; ++j)
				cin >> current[i][j];

		boards.push_back(current);
	}
	
	ll answer;
	for(const ll& number: numbers) {
		if(someWon(number, boards, answer)) {
			cout << answer * number << endl;
			//return 0;
		}
	}
	return 0;
}
