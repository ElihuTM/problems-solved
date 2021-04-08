#include <bits/stdc++.h>

using namespace std;

int main()
{
	int casos, n, ans;
	vector <int > arr;

	cin >> casos;
	while( casos-- )
	{
		cin >> n;

		ans = 0;
		arr.resize( n );
		for( int i=0; i<n; ++i )
		{
			cin >> arr[ i ];
			for( int j = 0; j < i; ++j )
				if( arr[ j ] <= arr[ i ] )
					++ans;
		}

		cout << ans << '\n';
	}
	return 0;
}
