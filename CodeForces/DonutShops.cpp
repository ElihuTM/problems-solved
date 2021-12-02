#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t, a, b, c;
	cin >> t;

	while( t-- )
	{
		cin >> a >> b >> c;

		if( a < c )
			cout << "1 ";
		else
			cout << "-1 ";


		if( a*b > c )
			cout << b << '\n';
		else
			cout << -1 << '\n';

	}
	return 0;
}
