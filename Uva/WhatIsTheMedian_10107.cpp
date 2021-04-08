#include <bits/stdc++.h>
#define maxn 10003

using namespace std;

int arr[ maxn ];

int main()
{
	int it = 0;

	while( cin >> arr[ it++ ] )
	{
		sort( arr, arr+it );

		if( it&1 )
			cout << arr[ it/2 ] << '\n';
		else
			cout << ( arr[ it/2 ] + arr[ it/2 - 1 ])/2 << '\n';
	}
	return 0;
}
