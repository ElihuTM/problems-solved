#include <iostream>
#include <vector>
#define maxn 1000005

using namespace std;
typedef long long ll;

ll distances[maxn];
ll timeWaiting[maxn];
ll timeLanding1[maxn];
ll timeLanding2[maxn];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;	
	cin >> n; 

	for(int i=0; i<n-1; ++i)
		cin >> distances[i];

	for(int i=0; i<n; ++i)
		cin >> timeWaiting[i];

	timeLanding1[0] = timeLanding2[n-1] = 0;
	for(int i=1; i<n; ++i) {
		timeLanding1[i] = timeLanding1[i - 1] + timeWaiting[i - 1] + distances[i - 1];
		timeLanding2[n-i-1] = timeLanding2[n-i] + timeWaiting[n-i] + distances[n-i-1];
	}
	
	ll ans = 0;
	for(int i=0; i<n; ++i) {
		pair<ll,ll> one(timeLanding1[i], timeLanding1[i] + timeWaiting[i]);
		pair<ll,ll> two(timeLanding2[i], timeLanding2[i] + timeWaiting[i]);
		
		if(two.second < one.first || one.second < two.first)
			continue;
		
		if(one.first <= two.first && two.first <= one.second) {
			if(two.second < one.second) {
				ans = two.second - two.first;
			} else {
				ans = one.second - two.first;
			}
		} else {
			ans = two.second - one.first;
		}
		break;
	}
	
	cout << ans << endl;
	return 0;
}

