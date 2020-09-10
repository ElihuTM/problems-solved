#include <bits/stdc++.h>

using namespace std;

int main()
{
	string cad;
	cin >> cad;

	vector <int> ans;
	for( int i = 0; i<cad.size(); i+=2 )
		ans.push_back( cad[ i ] - '0' );
	
	sort( ans.begin(), ans.end() );
	
	cout << ans[ 0 ];
	for( int i = 1; i<ans.size(); ++i )
		cout << '+' << ans[ i ];
	cout << '\n';
	return 0;
}
