#include <iostream>

using namespace std;

int main()
{
	string cad;

	cin >> cad;

	int ans = 10;
	for (int i = 1; i < cad.size(); ++i)
		ans = (ans * 16 + cad[ i ] - '0') % 2;

	cout << ans; 
	return 0;
}