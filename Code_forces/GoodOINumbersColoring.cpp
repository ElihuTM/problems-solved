#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, t;

	cin >> t;
	while( t-- )
	{
		cin >> a >> b;
		if ( __gcd(a,b) == 1)
			cout << "Finite\n";
		else
			cout << "Infinite\n";
	}
	return 0;
}