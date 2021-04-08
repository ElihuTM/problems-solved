#include <bits/stdc++.h>

using namespace std;

int main()
{
	string cad;
	cin >> cad;
	int len = (cad.size() - 2) * 2;

	cout << 'h';
	for( int i = 0; i < len; ++i )
		cout << 'e';
	cout <<"y\n";

	return 0;
}
