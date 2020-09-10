#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, a, b;
	string ans, aux;

	cin >> t;
	while( t-- )
	{
		cin >> n >> a >> b;
		ans = ""; aux ="";

		for ( int i = 0; i < b; ++i)
			aux.push_back( 'a'+i );

		for (int i = 0; i < n; ++i)
			ans.push_back( aux[ i%aux.size() ] );

		cout << ans << '\n';
	}

	return 0;
}	