#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll l, n, it;
	cin >> l >> n;

	for ( it = 1; l % n ; ++it)
		n = n - (l % n);

	cout << it << '\n';
	return 0;
}