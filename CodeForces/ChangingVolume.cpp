#include <bits/stdc++.h>
#define maxn 100000

using namespace std;

int main()
{
	int t,a,b, n, ans;

	cin >> t;
	while( t-- )
	{
		cin >> a >> b;
		n = abs( b-a );
		ans = n / 5; n %= 5;
		ans += n / 2; n %= 2;
		ans += n;

		cout << ans << '\n';
	}
	return 0;	
}