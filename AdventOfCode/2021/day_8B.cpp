#include <bits/stdc++.h>

using namespace std;

struct entry {
	vector<string> patterns;
	vector<string> digits;
	vector<int> numbers;

	bool isDecrypted;

	entry(string input) {
		isDecrypted = false;
		numbers.assign(10, 0);

		stringstream ss(input);
		for(int i=0; i<10; ++i) {
			ss >> input;
			patterns.push_back(input);
		}
		ss >> input;
		for(int i=0; i<4; ++i) {
			ss >> input;
			digits.push_back(input);
			patterns.push_back(input);
		}
	}
	
	int toBinary(string cad) {
		int ans = 0;
		for(char letter: cad)
			ans |= (1<<(letter - 'a'));

		return ans;
	}

	void getEasyNumbers() {
		vector<pair<int,int>> correlations = {{2,1}, {3,7}, {4,4}};
		for(string pattern: patterns)
			for(auto correlation: correlations)
				if(pattern.size() == correlation.first)
					numbers[correlation.second] = toBinary(pattern);

		if(numbers[1] == 0 && numbers[4] != 0 && numbers[7] != 0)
			numbers[1] = (numbers[4] & numbers[7]);
	}

	void get5Numbers(int current) {
		if(numbers[3] == 0){
			if(numbers[1] != 0 && ((current & numbers[1]) == numbers[1]))
				numbers[3] = current;
		}
		
		if(numbers[5] == 0) {
			if(numbers[6] != 0 && ((current & numbers[6]) == current))
				numbers[5] = current;

			if(numbers[9] != 0 && ((current & numbers[9]) == current))
				numbers[5] = current;
		}


		if(numbers[2] != 0 && current != numbers[2]) {
			if((current | numbers[2]) == numbers[8])
				numbers[5] = current;
			else
				numbers[3] = current;
		} 

		if(numbers[5] != 0 && current != numbers[5]) {
			if((current | numbers[5]) == numbers[8])
				numbers[2] = current;
			else
				numbers[3] = current;

		}
	}
	
	void get6Numbers(int current) {
		if(numbers[6] == 0) {
			if(numbers[1] != 0 && ((current & numbers[1]) != numbers[1]))
				numbers[6] = current;

			if(numbers[7] != 0 && ((current & numbers[7]) != numbers[7]))
				numbers[6] = current;
		}

		if(numbers[0] == 0) {
			if(numbers[5] != 0 && ((current | numbers[5]) == numbers[8]))
				numbers[0] = current;
		}
		
		if(numbers[9] == 0) {
			if(
				numbers[1] != 0 
				&& numbers[2] != 0 
				&& numbers[3] != 0 
				&& ((numbers[2] & current) | numbers[1]) == numbers[3]
			)
				numbers[9] = current;

		}
	}
	
	bool checkIfWasDecrypted() {
		for(string digit: digits) {
			bool found = false;
			for(int i =0; i<10; ++i)
				if(numbers[i] == toBinary(digit))
					found = true;

			if(!found)
				return false;
		}

		return true;
	}

	void tryDecrypt() {
		numbers[8] = toBinary("abcdefg");
		for(int i=0; i<8; ++i) {
			getEasyNumbers();
			for(string pattern: patterns)
				if(pattern.size() == 5)
					get5Numbers(toBinary(pattern));
				else if(pattern.size() == 6)
					get6Numbers(toBinary(pattern));
		}

		isDecrypted = checkIfWasDecrypted();
	}

	int getValue() {
		map<int,int> correlation;
		int ans=0;
		for(int i=0; i<10; ++i)
			correlation[numbers[i]] = i;

		for(string digit: digits)
			ans = (ans * 10) + correlation[toBinary(digit)];

		return ans;
	}

	void print() {
		for(string pattern: patterns)
			cout << pattern << ' ';
		cout << " | ";
		for(string digit: digits)
			cout << digit << ' ';
		cout << endl;
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
	for(entry ent: entries) {
		ent.tryDecrypt();
		if(!ent.isDecrypted) {
			ent.print();
			for(int i=0; i<10; ++i)
				cout << i << ": " << ent.numbers[i] << ' ';
			cout << " | ";
			for(string digit: ent.digits)
				cout << ent.toBinary(digit) << ' ';
			cout << endl;
		}
		else {
			ans += ent.getValue();
		}
	}
	cout << ans << endl;
}

int main() {
	getInput();
	getOutput();
	return 0;
}
