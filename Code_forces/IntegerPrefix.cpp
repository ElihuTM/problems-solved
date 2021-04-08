#include <bits/stdc++.h>

using namespace std;

int main()
{
	string cad, ans;

	cin >> cad;
	int i = 0;

	while( cad[ i ] >= '0' && cad[ i ] <= '9' )
	{
		ans.push_back( cad[ i ] );
		++i;
	}
	if( ans.size() )
		cout << ans << '\n';
	else
		cout << "-1\n";
	return 0;
}
