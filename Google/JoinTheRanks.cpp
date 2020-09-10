
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, r, s;
	vector< pair <int,int> > ans;
	cin >> t;

	for (int c = 1; c <= t; ++c)
	{
		cout << "Case #" << c << ": ";
		ans.clear();
		cin >> r >> s;

		while( r > 1 )
		{
			for (int i = 1; i < s; ++i)
			{
				ans.emplace_back( r, r*s - (r+i) );
			}
			--r;
		}

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[ i ].first << ' ' << ans[ i ].second << '\n';
	}
	return 0;
}