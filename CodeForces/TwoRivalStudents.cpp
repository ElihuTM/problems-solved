#include <bits/stdc++.h>
#define maxn 100000

using namespace std;

int main()
{
	int t, n, a, b, x;

	cin >> t;
	while( t-- )
	{
		cin >> n >> x >> a >> b;
		cout << min( n-1, abs(b-a)+x ) << '\n';
	}
	return 0;	
}