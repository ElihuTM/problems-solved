#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

long long arr[ maxn ];

int main()
{
	int n, a;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		arr[ a ]++;
	}

	for (int i = 2; i < maxn; ++i)
		arr[ i ] = max( arr[ i-1 ], arr[ i-2 ] + i*arr[ i ] );
	cout << arr[ maxn-1 ] << '\n';
	return 0;
}