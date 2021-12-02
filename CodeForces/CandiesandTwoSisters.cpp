#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		if ( n < 2 )
		{
			cout << "0\n";
			continue;
		}

		if ( n&1 )
			cout << n/2 << '\n';
		else
			cout << n/2 - 1 << '\n';
	}
	return 0;
}	