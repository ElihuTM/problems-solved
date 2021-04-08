#include <bits/stdc++.h>

using namespace std;

vector< int > ans;

int main()
{
	int n, a;

	cin >> n;
	while( n )
	{
		ans.clear();
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			if( a )
				ans.push_back( a );
		}

		if ( ans.size() == 0)
			cout << "0\n";
		else
		{
			cout << ans[ 0 ];
			for (int i = 1; i < ans.size(); ++i)
				cout << " " << ans[ i ];
			cout << '\n';
		}

		cin >> n;
	}
	return 0;
}