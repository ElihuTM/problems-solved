#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	int n;
	ll sum, a = 0, maxi = 0;

	cin >> n;
	for( int i = 0; i < n; ++i )
	{
		cin >> a;
		if( a > maxi )
			maxi =  a;

		sum += a;
	}

	if( sum&1 || 2*a > sum )
		cout << "NO\n";
	else
		cout << "YES\n";
	return 0;
}
