#include <bits/stdc++.h>
#define ss second
#define ff first

using namespace std;
typedef pair <int,int> pii;

int main()
{
	string s, t;
	int car[ 27 ];
	int k, n;

	cin >> k;
	while( k-- )
	{
		memset( car, 0, sizeof car );
		cin >> n;
		cin >> s;
		cin >> t;

		for (int i = 0; i < n; ++i)
		{
			++car[ s[ i ]-'a'];
			++car[ t[ i ]-'a'];
		}

		bool is_pos = true;
		for (int i = 0; i < 26; ++i)
			if ( car[ i ]&1)
			{
				cout << "No\n";
				is_pos = false;
				break;
			}
		
		if ( !is_pos )
			continue;

		cout << "Yes\n";
		vector<pii> ans;
		for (int i = 0; i < n; ++i)
		{
			if ( s[ i ] != t[ i ] )
			{
				for (int j = i+1; j < n; ++j)
					if (s[ i ] == s[ j ] )
					{
						ans.emplace_back( j, i );
						swap( s[ j ], t[ i ] );
						break;
					}
				
				if ( s[ i ] != t[ i ] )
				{
					for (int j = i+1; j < n; ++j)
					{
						if (s[ i ] == t[ j ] )
						{
							ans.emplace_back( j, j );
							ans.emplace_back( j, i );
							swap( s[ j ], t[ j ] );
							swap( s[ j ], t[ i ] );
							break;
						}
					}
				}
			}
		}

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[ i ].ff +1<< " " << ans[ i ].ss+1 << '\n';
	}
	return 0;
}