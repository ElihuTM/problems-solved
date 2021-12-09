#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

vi getInput() {
	vi reps(10, 0);
	string cad;

	cin >> cad;
	for(char letter: cad)
		if(isdigit(letter))
			reps[letter - '0']++;

	return reps;
}

void getOutput(vi reps,int days) {
	while(days--) {
		ll aux = reps[0];
		for(int i=0; i<reps.size()-1; ++i)
			reps[i] = reps[i+1];

		reps[8] += aux;
		reps[6] += aux;
	}

	ll ans = 0;
	for(ll rep: reps)
		ans += rep;

	cout << ans << endl;
}

int main() {
	vi reps = getInput();
	getOutput(reps, 256);
	return 0;
}
