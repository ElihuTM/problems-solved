#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair<int,int> pii;

pii gen( int a, int b, int n )
{
	pii ans;

	for (int i = 0; i < n-1; ++i)
	{
		ans.ff = ((ans.ff * 10) + a ) % a;
		ans.ss = ((ans.ss * 10) + a ) % b;
	}

	ans.ff = ((ans.ff * 10) + b ) % a;
	ans.ss = ((ans.ss * 10) + b ) % b;
	return ans;
}

int main()
{
	pii ans[ 10 ][ 10 ];
	int t, n;
	bool flag;
	cin >> t;
	
	while( t-- )
	{
		cin >> n;

		for (int i = 2; i < 10; ++i)
			for (int j = 2; j < 10; ++j)
				ans[ i ][ j ] = gen( i, j, n );

		flag = true;
		for (int i = 2; (i < 10 && flag); ++i)
			for (int j = 2; (j < 10 && flag); ++j)
			{
				if ( ans[ i ][ j ].ff != 0 && ans[ i ][ j ].ss != 0 )
				{
					flag = false;
					for (int k = 0; k < n-1; ++k)
						cout << i;
					cout << j << '\n';
				}
			}

		if( flag )
			cout << "-1\n";
	}
	return 0;
}