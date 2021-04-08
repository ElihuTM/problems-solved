#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int s, t;

void c_s( int pos, int val )
{
	if( val < 0 ) return;

	if( pos == t )
	{
		if( val == 0 )
		{
			cout << ans[ 0 ];
			for( int i = 1; i < ans.size(); ++i )
				cout << " " << ans[ i ];

			cout << '\n';
			return;
		}
	}
	
	int start = (ans.empty() ? 1 : ans.back() );

	for( int i = start; i <= val; ++i )
	{
		bool ban = true;
		for( int j = 0; j < pos; ++j )
			if( __gcd( i, ans[ j ] ) != 1 )
			{
				ban = false;
				break;
			}
		
		if( ban )
		{
			ans.push_back( i );
			c_s( pos+1, val-i );
			ans.pop_back();
		}
	}
}

int main()
{
	int casos;

	cin >> casos;
	for( int it = 1; it <= casos; ++it )
	{
		cin >> s >> t;

		cout << "Case " << it << ":\n";
		c_s( 0, s );
	}
	return 0;
}
