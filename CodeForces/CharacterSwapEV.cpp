#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;
typedef pair <char,char> pcc;

int main()
{
	string cad1, cad2;
	//int nums[ 2 ][ 27 ];
	int t, n;

	cin >> t;
	while( t-- )
	{
		//memset( nums, 0, sizeof nums );
		vector< pcc > dife;
		cin >> n;
		cin >> cad1;
		cin >> cad2;

		for (int i = 0; i < n; ++i)
			if( cad1[ i ] != cad2[ i ] )
				dife.push_back( pcc(cad1[ i ],cad2[ i ] ) );
	
		if ( dife.size() != 2 || dife[ 0 ].ff != dife[ 1 ].ff || dife[ 0 ].ss != dife[ 1 ].ss )
			cout << "NO\n";
		else
			cout << "YES\n";

	}
	return 0;
}