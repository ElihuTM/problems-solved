#include <bits/stdc++.h>
#define maxn 200005

using namespace std;

bool visit[ maxn ];
int letter[ 27 ];
string str;
int n, k;

int fun( int a )
{
	int cont = 0;
	memset( letter, 0, sizeof letter );

	for (int i = a; i < n; i += k )
	{
		if ( !visit[ i ] )
		{
			letter[ str[ i ] -'a' ]++;
			visit[ i ] = true;
			++cont;
		}

		if ( !visit[ n-i-1 ] )
		{
			letter[ str[ n-i-1 ] -'a' ]++;
			visit[ n-i-1 ] = true;
			++cont;
		}
	}

	int maxi = 0;
	for (int i = 0; i < 27; ++i)
		maxi = max( maxi, letter[ i ] );

	return cont - maxi;
}

int main()
{
	int t, ans;

	cin >> t;
	while( t-- )
	{
		cin >> n >> k;
		cin >> str;

		for (int i = 0; i < n; ++i)
			visit[ i ] = 0;

		ans = 0;
		for (int i = 0; i < n; ++i)
			if ( !visit[ i ] )
				ans += fun( i );

		cout << ans << '\n';
	}
	return 0;
}	