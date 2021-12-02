#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, a, b, c, d, k, aa, bb;
	cin >> n;

	while( n-- )
	{
		cin >> a >> b >> c >> d >> k;
		aa = ceil((double)a/(double)c);
		bb = ceil((double)b/(double)d);

		if( aa + bb <= k )
			cout << aa << " " << bb << '\n';
		else
			cout << -1 << '\n';
	}
	return 0;
}
