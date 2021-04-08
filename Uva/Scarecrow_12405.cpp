#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;
	string cad;

	cin >> t;
	for( int qw = 1; qw <= t; ++qw )
	{
		cin >> n;
		cin >> cad;

		int ini = 0;
		while( cad[ ini ] == '#' ) ++ini;
		
		int ans = 0;
		while( ini < n )
			if( cad[ ini ] == '.' )
			{
				++ans;
				ini += 3;
			}
			else
				++ini;

		cout << "Case " << qw << ": " << ans << '\n';
	}
}
