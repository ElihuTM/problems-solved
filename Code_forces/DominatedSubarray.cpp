#include <bits/stdc++.h>
#define maxn 100000
#define inf 999999999

using namespace std;

vector<int> ant;
vector<int> arr; 

int main()
{
	int t, n;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		ant.assign( n+1, -1);
		arr.resize( n );
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		int ans = inf;
		for (int i = 0; i < n; ++i)
		{
			if ( ant[ arr[ i ] ] != -1 )
				ans = min( i-ant[ arr[ i ] ]+1, ans );

			ant[ arr[ i ] ] = i;
		}

		if ( n == 0 || ans == inf )
			cout << "-1\n";
		else
			cout << ans << '\n';
	}
	return 0;	
}