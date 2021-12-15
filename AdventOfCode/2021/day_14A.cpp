#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef map<string, ll> msi;
typedef map<string, char> msc;

msi nextIteration(msi reps, msc dict) {
	msi ans;
	for(auto c: reps) {
		char newLetter = dict[c.first];
		ans[{c.first[0], newLetter}] += c.second;
		ans[{newLetter, c.first[1]}] += c.second;
	}
	return ans;
}

int main() {
	string cad, par, arrow;
	vector<ll>counter(27,0);
	msc dict;
	msi reps;

	int it = 40;
	char letter;

	cin >> cad;
	while(cin >> par >> arrow >> letter)
		dict[par] = letter;

	for(int i=1; i<cad.size(); ++i)
		reps[{cad[i-1], cad[i]}]++;

	while(it--)
		reps = nextIteration(reps, dict);
	
	for(auto c: reps) {
		counter[c.first[0] - 'A'] += (c.second / 2);
		counter[c.first[1] - 'A'] += (c.second / 2);
	}

	ll maxi = 0, mini = 0;
	for(int i=0; i<27; ++i) {
		if(counter[i] > 0) {
			mini = (mini == 0 ? counter[i] : min(mini, counter[i]));
			maxi = max(maxi, counter[i]);
		}
	}
	cout << maxi - mini << endl;
	return 0;
}
