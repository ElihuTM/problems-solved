#include <bits/stdc++.h>
#define maxn 1000000

using namespace std;

int arr[ 10000000 ];
vector< int > ans;
map< pair<int,int> , int > memo;

int dp( int pos, int num )
{
	if( num < 0 )
		return 0;

	if( pos == ans.size() )
		return num == 0 ? 1 : 0;

	if( memo.find(make_pair( pos, num ) ) != memo.end() )
		return memo[ make_pair(pos, num) ];

	return memo[ make_pair( pos, num ) ] = dp( pos+1, num ) + dp( pos+1, num - ans[ pos ] ); 
}

bool calc( int n )
{
	//memo.clear();
	if( dp( 0, n) > 0 )
		return true;

	return false;
}

int main()
{
	int n, len;

	cin >> n;
	len = (1 << n );
	for (int i = 0; i < len; ++i)
		cin >> arr[ i ];

	sort( arr, arr + len );

	ans.push_back( arr[ 1 ] );
	ans.push_back( arr[ 2 ] );

	for( int i = 3; i < len; ++i )
	{
		bool is = calc( arr[ i ] );

		if( !is)
		{
			if( ans.size() < n )
				ans.push_back( arr[ i ] );
			else
			{
				cout << "impossible\n";
				return 0;
			}
		}
	}

	for (int i = 0; i < n; ++i)
		cout << ans[ i ] << '\n';
	
	return 0;
}