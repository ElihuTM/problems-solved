#include <bits/stdc++.h>

using namespace std;

int main()
{
	string cad;

	cin >> cad;
	while( cad != "#" )
	{
		if( next_permutation( cad.begin() , cad.end() ) )
			cout << cad << '\n';
		else
			cout << "No Successor\n";
		cin >> cad;
	}
	return 0;
}
