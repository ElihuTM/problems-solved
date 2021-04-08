#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, c, a;
	
	cin >> n >> c;
	vector<int> arr( n );
	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	sort( arr.begin(), arr.end() );

	int i = 0, j = n-1, ans = 0;
	while( j >= i )
	{
		if ( j == i )
		{
			++ans;
			break;
		}

		if ( arr[ j ] + arr[ i ] <= c )
			++i;

		--j;
		++ans;
	}

	cout << ans << '\n';
	return 0;
}