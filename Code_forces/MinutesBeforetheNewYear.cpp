#include <bits/stdc++.h>

using namespace std;

int main()
{
	int hour, min, ans, t;

	cin >> t;
	while( t-- )
	{
		cin >> hour >> min;
		ans = 60 - min;
		++hour;

		ans += (24 - hour) * 60;
		cout << ans << '\n';
	}
	return 0;
}