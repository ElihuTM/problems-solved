#include <bits/stdc++.h>
#define maxn 1800

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

ll reps[maxn];

void getInput() {
	memset(reps, 0, sizeof(reps));
	string cad;
	cin >> cad;

	for(char& letter: cad)
		if(letter == ',')
			letter = ' ';

	stringstream ss(cad);
	ll number, maxi = 0;
	while(ss >> number)
		reps[number]++;
}

ll gauss(ll n) {
	return n*(n+1) / 2;
}

ll moveTo(ll target) {
	ll ans = 0;
	for(ll i=0; i<maxn; ++i)
		ans += reps[i]*gauss(abs(target-i));

	return ans;
}

void getOutput() {
	ll mini = maxn * gauss(maxn);
	for(int i=0; i<maxn; ++i)
		mini = min(mini, moveTo(i));
	cout << mini << endl;
}
int main() {
	getInput();
	getOutput();
	return 0;
}
