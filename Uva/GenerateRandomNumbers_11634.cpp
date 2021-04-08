#include <bits/stdc++.h>
#define maxn 100000

using namespace std;

int main()
{
	int arr[ maxn ];
	int a, it;
	cin >> a;

	while( a )
	{
		memset( arr, -1, sizeof arr );
		it = 0;

		while( arr[ a ] == -1 )
		{
			arr[ a ] = it++;
			a = ((a*a)/100) % 10000;
		}

		cout << it << '\n';
		cin >> a;
	}

	return 0;
}
