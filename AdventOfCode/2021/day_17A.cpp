#include <bits/stdc++.h>
#define maxn 10500

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

pii target_x;
pii target_y;

void getHighPosition(int x, int y, ll& ans) {
	pii current;
	ll highPosition = 0;
	while(current.first <= target_x.second && current.second >= target_y.first) {	
		if(target_x.first <= current.first && current.first <= target_x.second &&
				target_y.first <= current.second && current.second <= target_y.second) {
			++ans;
			return;
		}

		highPosition = max(highPosition, current.second);
		current.second += y;
		current.first += x;
		x -= (x != 0);
		y--;
	}
}

ll getHighestPosition() {
	ll ans = 0;
	for(int y=target_y.first; y<maxn; ++y)
		for(int x=1; x<=target_x.second; ++x)
			getHighPosition(x,y, ans);	
	return ans;
}

int main() {
	cin >> target_x.first >> target_x.second;
	cin >> target_y.first >> target_y.second;

	cout << getHighestPosition() << endl;
	return 0;
}
