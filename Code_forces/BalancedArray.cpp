#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll t, n;

	cin >> t;
	while( t-- )
	{
		cin >> n;

		if ( (n/2)&1 )
			cout << "NO\n";
		else
		{
			cout << "YES\n";
			ll sum = 0;
			for (int i = 0; i < n/2; ++i)
			{
				cout << 2*(i+1) << ' ';
				sum += 2*(i+1);
			}

			for (int i = 0; i < n/2 - 1; ++i)
			{
				cout << 2*i + 1 << ' ';
				sum -= 2*i + 1;
			}
			cout << sum << '\n';
		}
	}
	return 0;
}