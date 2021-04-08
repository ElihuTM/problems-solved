#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, k, aux, ans;
	string cad;
	
	cin >> t;

	while( t-- )
	{
		cin >> n >> k;
		cin >> cad;
		
		ans = 0;
		for( int i = 0; i < n-k; ++i )
		{
			aux = 1;
			for( int j = 0; j < k; ++j )
				aux *= (cad[ i+j ] - '0');
			ans = max( ans, aux );
		}

		cout << ans << '\n';
	}
	return 0;
}
