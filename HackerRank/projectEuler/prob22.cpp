#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector <string> dic;

int main()
{
	int n;
	string cad;

	cin >> n;
	while( n-- )
	{
		cin >> cad;
		dic.push_back( cad );
	}
	sort( dic.begin(), dic.end() );

	cin >> n;
	while( n-- )
	{
		int it = 0;
		cin >> cad;

		while( dic[ it ] != cad )
			++it;

		ll ans = 0;
		for( int i = 0; i < dic[ it ].size(); ++i )
			ans += dic[ it ][ i ] - 'A';

		cout << ans*(it+1) << '\n';
	}

	return 0;
}
