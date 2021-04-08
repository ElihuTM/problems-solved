#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, ans = 0;
	while( cin >> n ) {
		n = n / 3 - 2;
		while( n > 0 ) {
			ans += n;
			n = n / 3 - 2;
		}
	}

	cout << ans << endl;
	return 0;
}