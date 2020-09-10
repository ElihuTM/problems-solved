#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n;
	stack <char> ans;
	string cad;
	cin >> t;

	while( t-- )
	{
		cin >> n;
		cin >> cad;
	
		int cont = 0;
		for( int i = cad.size()-1; i>=0; --i)
			if( cad[ i ] == '0' )
				++cont;
			else
			{
				if( cont == 0 )
					ans.push( cad[ i ] );
				else if( cont > 1 )
					cont = 1;
			}

		for( int i = 0; i<cont; ++i)
			cout << '0';

		while( !ans.empty() )
		{
			cout << ans.top();
			ans.pop();
		}
		cout << '\n';
	}
	return 0;
}
