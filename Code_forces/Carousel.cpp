#include <bits/stdc++.h>
#define maxn 200017

using namespace std;

int arr[ maxn ];
int ans[ maxn ];

int three( int n, int cont )
{
	ans[ 0 ] = 0;
	if ( cont == 1 )
	{
		for (int i = 1; i < n; ++i)
			ans[ i ] = 0;

		return 1;
	}

	if ( (cont&1) == 0 )
	{
		for (int i = 1; i < n; ++i)
			if ( arr[ i ] == arr[ i-1 ] )
				ans[ i ] = ans[ i-1 ];
			else
				ans[ i ] = 1 - ans[ i-1 ];

		return 2;
	}

	bool exist = false;
	for (int i = 1; i < n; ++i)
	{
		if ( arr[ i ] == arr[ i-1 ] )
		{
			if ( exist )
				ans[ i ] = ans[ i-1 ];
			else
			{
				ans[ i ] = 1 - ans[ i-1 ];
				exist = true;
			}
		}
		else
			ans[ i ] = 1 - ans[ i-1 ];
	}

	if ( !exist )
	{
		if ( arr[ n-1 ] == arr[ 0 ] )
		{
			ans[ n-1 ] = 0;
			return 2;
		}
		else
		{
			ans[ n-1 ] = 2;
			return 3;
		}
	}

	return 2;
}

int main()
{
	int t, n, k, cont;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		cont = 1;
		for (int i = 1; i < n; ++i)
			if ( arr[ i ] != arr[ i-1 ] )
				++cont;

		k = three( n, cont );

		cout << k << '\n';
		for (int i = 0; i < n-1; ++i)
			cout << ans[ i ]+1 << ' ';
		cout << ans[ n-1 ]+1 << '\n';
	}
	return 0;
}