#include <bits/stdc++.h>
#define maxn 103

using namespace std;

int main()
{
	string cad;
	int unos = 0;
	char ans;
	int len;

	cin >> len;
	cin >> cad;

	for( int i = 0; i < len; ++i )
		if( cad[ i ] == '1' )
			++unos;
	
	if( unos*2 == len )
	{
		ans = cad[ len-1 ];
		cad.pop_back();

		cout << "2\n" << cad << " " << ans << '\n';
	}
	else
		cout << "1\n" << cad << endl;
	return 0;
}
