#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, ans, j;
	string str;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		cin >> str;

		ans = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if( str[ i ] == 'A')
			{
				j = 0;
				while( i+j+1 < str.size() && str[ i+j+1 ] == 'P' )
					++j;

				ans = max( ans, j );
			}
		}

		cout << ans << '\n';
	}
	return 0;
}