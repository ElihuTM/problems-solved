#include <bits/stdc++.h>

using namespace std;

set <int> dic;

bool exist_rest( int a, int b )
{
	if ( dic.find( a ) == dic.end() )
		return true;

	if ( dic.find( b ) == dic.end() )
		return true;

	return false;
}

int main()
{
	int t, n, s, k, a;

	cin >> t;
	while( t-- )
	{
		cin >> n >> s >> k;
		dic.clear();

		for (int i = 0; i < k; ++i)
		{
			cin >> a;
			dic.insert( a );
		}

		for (int i = 0; i <= 1000; ++i)
		{
			if( exist_rest( max(1, s-i), min(n,s+i) ) )
			{
				cout << i << '\n';
				break;
			}
		}
	}
	return 0;
}