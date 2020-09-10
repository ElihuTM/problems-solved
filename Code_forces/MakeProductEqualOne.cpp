#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, val = 1, a;
	long long ans = 0;
	bool exist_a_zero = false;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		if ( a > 0 )
			ans += a-1;
		else if( a == 0 )
		{
			++ans;
			exist_a_zero = true;
		}
		else
		{
			ans += -(a+1);
			val *= -1;
		}
	}

	if ( val == -1 && !exist_a_zero )
		ans += 2;

	cout << ans << '\n';
}