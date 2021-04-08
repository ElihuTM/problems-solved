#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,b,p;
	cin >> n >> b >> p;

	int x = 0, y = 0;

	y = p*n;
	while( n > 1 )
	{
		x += b *( n - (n&1) );
		x += n/2;

		n = n/2 + (n&1);
	}

	cout << x << " " << y << '\n';
	return 0;
}