#include <bits/stdc++.h>
#define maxn 20000

using namespace std;

int arr[ maxn ];
int ans[ maxn ];

int main()
{
	int a, n, pos = 0, neg = 0;
	cin >> n;

	for( int i = 0; i < n; ++i )
	{
		cin >> a;
		arr[ i ] = a;

		if( a < 0 )
			neg += a/2;
		else
			pos += a/2;

		ans[ i ] = a/2;
	}

	for( int i = 0; i < n; ++i )
	{
		if( abs(neg) < abs(pos) && arr[ i ] < 0 && (abs(arr[ i ])&1) )
		{
			--neg;
			--ans[ i ];
		}
		else if( abs(pos) < abs(neg) && arr[ i ] >= 0 && (arr[ i ] & 1) )
		{
			++pos;
			++ans[ i ];
		}
	}

	cout << ans[ 0 ];
	for( int i = 1; i < n; ++i )
		cout << " " << ans[ i ];
	cout << endl;

	return 0;
}
