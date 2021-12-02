#include <bits/stdc++.h>

using namespace std;

int main()
{
	bool arr[ 1004 ]; 
	int n, k, a;
	int ans = 0;

	memset( arr, 0 , sizeof arr );
	cin >> n >> k;
	for( int i= 0; i < n; ++i)
	{
		cin >> a;
		if( arr[ a ] )
		{
			arr[ a ] = 0;
			ans += 2;
		}
		else
			arr[ a ] = 1;
	}
	
	int cont = 0;
	for( int i = 1; i <= k; ++i )
		cont += arr[ i ];
	
	ans += ceil( (float)cont/2 );
	cout << ans << '\n';

	return 0;
}
