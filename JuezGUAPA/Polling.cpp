#include <bits/stdc++.h>

using namespace std;

int main()
{
	map<string, int> votes;
	string cad;
	int n, max_votes = 0;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> cad;
		votes[ cad ]++;

		max_votes = max( max_votes, votes[ cad ] );
	}

	set<string> ans;
	for ( auto c: votes )
		if ( c.second == max_votes )
			ans.insert( c.first );

	for ( auto c: ans )
		cout << c << '\n';
	
	return 0;
}	