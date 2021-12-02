#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;
	bool even;

	vector<int> v;
	vector<int> ans;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		v.resize( n );
		ans.clear();

		for (int i = 0; i < n; ++i)
		{
			cin >> v[ i ];
			if ( (v[ i ]%2) == 0 )
				ans.push_back( i+1 );
		}

		even = false;
		if ( ans.size() == 0 and v.size() > 1 )
			for (int i = 0; i < n; ++i)
			{
				ans.push_back( i+1 );
				if ( even )
					break;
				else
					even = true;
			}
		
		if ( ans.size() > 0 )
		{
			cout << ans.size() << '\n';
			for (int i = 0; i < ans.size(); ++i)
				cout << ans[ i ] << ' ';
			cout << '\n';	
		}
		else
			cout << "-1\n";
	
	}
	return 0;
}