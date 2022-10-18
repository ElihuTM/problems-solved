#include <iostream>
#include <vector>
#include <algorithm>

#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;

vector<ll> funnyNumbers;
ll n, x;

ll comb(int pos, int remains, ll value) {
	if(remains < 0 || value > x)
		return 0;

	if(pos == n)
		return (remains > 0 ? 0 : x / value);

	return (comb(pos+1, remains, value) + comb(pos+1, remains-1, value*funnyNumbers[pos]));
}

void readFunnyNumbers() {
	vector<int> aux(n);

	for(int i=0; i<n; ++i)
		cin >> aux[i];
	
	sort(all(aux));
	
	for(int b: aux) {
		if( !any_of(all(funnyNumbers), [&b](int a){ return (b%a == 0); }))
			funnyNumbers.push_back(b);
	}
	n = funnyNumbers.size();
}

int main() {
	cin >> n >> x;
	readFunnyNumbers();
		
	ll ans = 0;
	for(int i=1; i<=n; ++i) {
		const int sgn = ((i&1) ? 1 : -1);
		ans += sgn * comb(0, i, 1);
	}

	cout << ans << endl;
	return 0;
}

