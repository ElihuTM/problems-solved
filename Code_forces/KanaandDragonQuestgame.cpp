#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, k, n, m;

	cin >> t;
	while( t-- )
	{
		cin >> k >> n >> m;

		while( k > 10*m && n > 0 )
		{
			k = k/2 + 10;
			--n;
		}

		if ( k <= 10*m)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}	
	