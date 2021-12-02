#include <bits/stdc++.h>

using namespace std;

int main()
{
	int q,a,b,n,S;
	cin >> q;

	while( q-- )
	{
		cin >> a >> b >> n >> S;

		int cuenta = min( S/n, a );

		if ( S - (cuenta*n) <= b)
			cout << "YES\n";
		else
			cout << "NO\n";	
	}
	return 0;
}