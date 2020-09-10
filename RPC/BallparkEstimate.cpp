#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	string cad;

	cin >> cad;

	if (cad.size() == 1)
		cout << cad << '\n';
	else
	{
		for (int i = 2; i < cad.size(); ++i)
			cad[ i ] = '0';

		if (cad[ 1 ] >= '5' )
		{	
			if ( cad[ 0 ] == '9')
			{
				cad[ 0 ] = '0';
				cout << '1';
			}
			else
				cad[ 0 ]++;
		}

		cad[ 1 ] = '0';
		cout << cad << '\n';
	}
	return 0;
}