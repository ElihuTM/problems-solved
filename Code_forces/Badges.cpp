#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;

	if( a > b )
		swap( a,b );

	b = min( c, b );
	if( a >= c )
		cout << c+1 << '\n';
	else
		cout << a-c+b+1 << '\n';

	return 0;
}
