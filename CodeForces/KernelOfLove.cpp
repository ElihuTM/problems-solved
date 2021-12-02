#include <bits/stdc++.h>
#define maxn 100000

using namespace std;

int main()
{
	int k, n;
	cin >> k;

	while( k-- )
	{
		cin >> n;
		
		if( n == 1 || n == 2 )
			cout << "0\n";
		else if( n%3 == 0 )
			cout << (n/3) * 2 << '\n';
		else
			cout << (n/3) * 2 + 1 << '\n';
	}
	return 0;
}
