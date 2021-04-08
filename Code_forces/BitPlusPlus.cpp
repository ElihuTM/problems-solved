#include <iostream>

using namespace std;

int main()
{
	string cad;
	int ans = 0;
	int q;

	cin >> q;
	while( q-- )
	{
		cin >> cad;
		if( cad[ 1 ] == '+' )
			++ans;
		else
			--ans;
	}

	cout << ans << '\n';
	return 0;
}
