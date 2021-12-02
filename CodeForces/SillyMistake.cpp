#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int arr[ maxn ];

int main()
{
	int n;
	set <int> dic;
	set <int> use;

	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	vector<int> ans; ans.push_back( 0 );
	for (int i = 0; i < n; ++i)
	{
		if ( dic.find( arr[ i ] ) != dic.end() )
		{
			cout << "-1\n";
			return 0;
		}

		if ( !dic.empty() && use.find( arr[ i ] ) != use.end() )
		{
			cout << "-1\n";
			return 0;
		}

		if ( arr[ i ] > 0)
		{
			dic.insert( arr[ i ] );
			use.insert( arr[ i ] );
		}

		else
		{
			auto it = dic.find( -arr[ i ] );
			if ( it == dic.end() )
			{
				cout << "-1\n";
				return 0;
			}
			else
				dic.erase( it );
		}

		if ( dic.empty() )
		{
			use.clear();
			ans.push_back( i );
		}
	}

	if ( !dic.empty() )
		cout << "-1\n";
	else
	{
		cout << ans.size()-1 << '\n';
		cout << ans[ 1 ]+1;
		for (int i = 2; i < ans.size(); ++i)
			cout << " " << ans[ i ] - ans[ i-1 ];
		cout << '\n';
	}
	return 0;	
}