#include <bits/stdc++.h>

using namespace std;

bool is_pal( int n )
{
	int cop = n, rev = 0;
	for( int i = 0; i < 6; ++i )
	{
		rev = (rev*10) + (cop % 10);
		cop /= 10;
	}

	return n == rev;
}

int main()
{
	vector < int > ans;
	int t, x;
	cin >> t;

	for( int i = 100; i < 999; ++i )
		for( int j = 100; j < 999; ++j )
			if( i*j > 99999 && i*j < 1000000 && is_pal( i*j ) )
				ans.push_back( i*j );

	sort( ans.begin(), ans.end() );
	while( t-- )
	{
		cin >> x;
		
		int i = 0;
		while( i < ans.size() && ans[ i ] < x )
			++i;
		
		cout << ans[ i-1 ] << '\n';
	}
	return 0;
}
