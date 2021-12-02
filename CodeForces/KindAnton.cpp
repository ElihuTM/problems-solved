#include <bits/stdc++.h>
#define maxn 100007

using namespace std;

int a[ maxn ];
int b[ maxn ];

bool is_pos( int n )
{
	int pos = n+n, neg = n+n;

	for (int i = 0; i < n; ++i)
		if ( a[ i ] < 0 )
		{
			neg = i;
			break;
		}

	for (int i = 0; i < n; ++i)
		if ( a[ i ] > 0 )
		{
			pos = i;
			break;
		}


	for (int i = 0; i < n; ++i)
	{
		if ( a[ i ] == b[ i ] )
			continue;

		if ( a[ i ] < b[ i ] )
		{
			if ( pos >= i )
				return false;
		}
		else
		{
			if ( neg >= i )
				return false;
		}
	}

	return true;
}

int main()
{
	int t, n;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[ i ];

		for (int i = 0; i < n; ++i)
			cin >> b[ i ];

		if ( is_pos( n ) )
			cout << "YES\n";
		else
			cout << "NO\n";
	
	}
	return 0;
}	