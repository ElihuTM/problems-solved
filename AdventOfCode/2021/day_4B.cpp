#include<bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll,ll> pii;

vi numbers;
vector<vvi> boards;

void getInput() {
	numbers.clear();
	boards.clear();
	ll number;
	
	// Read numbers
	{
		string cad;

		getline(cin, cad);		
		for(char& letter: cad)
			if(letter == ',')
				letter = ' ';	
		stringstream ss(cad);

		while(ss >> number)
			numbers.push_back(number);
	}
	
	// Read boards
	{
		vvi current(5, vi(5));
		while(cin >> number) {	
			current[0][0] = number;

			for(int i=0; i<5; ++i)
				for(int j=(i==0); j<5; ++j)
					cin >> current[i][j];

			boards.push_back(current);
		}
	}
}

void mark(vvi& board, int number) {
	for(int i=0; i<5; ++i)
		for(int j=0; j<5; ++j)
			if(board[i][j] == number)
				board[i][j] = -1;
}

bool won(const vvi& board) {
	for(int i=0; i<5; ++i) {
		bool inRaw = true;
		bool inCol = true;
		for(int j=0; j<5; ++j) {
			inRaw = (inRaw && board[i][j] == -1);
			inCol = (inCol && board[j][i] == -1);
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

void printBoard(ll number, ll answer, vvi boards) {
	cout << number << ": " << answer << endl;
	for(auto row: boards) {
		for(auto value: row)
			cout << value << " ";
		cout << endl;
	}
	cout << endl;
}

void markNumber(ll number, vector<bool>& isWinner, ll& answer) {
	for(int i=0; i<boards.size(); ++i) {
		if(!isWinner[i]) {
			mark(boards[i], number);
			if(won(boards[i])) {
				isWinner[i] = true;
				answer = countPoints(boards[i]) * number;
			}
		}
	}
}

ll getOutput() {
	vector<bool> isWinner(boards.size(), false);
	ll answer = 0;

	for(ll number: numbers) {
		markNumber(number, isWinner, answer);
	}

	return answer;
}

int main() {
	getInput();
	cout << getOutput() << endl;
	return 0;
}
