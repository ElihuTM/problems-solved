#include<algorithm>
#include<functional>
#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

vector<string> reduceByBitCriteria(const vector<string>& bitNumbers, int position, function<bool(ll,ll)> comp) {
	if(bitNumbers.size() <= 1)
		return bitNumbers;
	
	vector<string> newBitNumbers;
	ll oneReps = 0, zeroReps = 0;
	for(const string& number: bitNumbers) {
		bool bit = number[position] - '0';
		oneReps += (bit == 1);
		zeroReps += (bit == 0);
	}

	bool numberToUse = comp(oneReps, zeroReps);
	for(const string& number: bitNumbers)
		if(number[position]- '0' == numberToUse)
			newBitNumbers.emplace_back(number);

	return newBitNumbers;
}

ll getRating(vector<string> criteriaList, function<bool(ll,ll)> comp) {
	int length = criteriaList.front().size(),
		rating = 0;

	for(int i=0; i<length; ++i)
		criteriaList = reduceByBitCriteria(criteriaList, i, comp);

	for(int i=0; i<length; ++i)
		rating = (rating * 2) + criteriaList.front()[i] - '0';
	
	return rating;
}

bool mostCommon(ll ones, ll zeros) { return (ones == zeros ? true : ones > zeros); }
bool leastCommon(ll ones, ll zeros) { return (ones == zeros ? false : ones < zeros); }

int main() {
	vector<string> bitNumbers;
	string cad;

	while(cin >> cad)
		bitNumbers.emplace_back(cad);	
		
	ll oxygenGenerator = getRating(bitNumbers, mostCommon);
	ll co2Scrubber = getRating(bitNumbers, leastCommon);

	cout << oxygenGenerator * co2Scrubber << endl;
	return 0;
}
