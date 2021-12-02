#include <bits/stdc++.h>

using namespace std;

bool is_pos( string &cad )
{
	if( cad.empty() )  return false;

	for( int i=0; i<cad.size()-1; ++i )
		if( cad[ i ] != cad[ i+1 ] )
			return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	string cad;

	cin >> t;
	while( t-- )
	{
		cin >> cad;
		int cont = 0;
		
		while( is_pos( cad ) )
		{
			for( int i=0; i<cad.size(); ++i)
				if(cad[ i ] != cad[ i+1 ] )
				{
					cad.erase(i,2);
					++cont;
					break;
				}
		}
		if( cont&1 )
			cout << "DA" << '\n';
		else
			cout << "NET" << '\n';
	}
	return 0;
}
