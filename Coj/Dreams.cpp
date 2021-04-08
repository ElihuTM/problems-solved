#include <iostream>
#include <bitset>
#define endl '\n'
#define maxn 1003

using namespace std;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int t, n, m, a, cont;
	bitset < maxn > arr;

	cin >> t;
	while( t-- )
	{
		cin >> n >> m;
		arr.set( );

		for (int i = 0; i < m; ++i)
		{
			cin >> a;
			arr[ a ] = false;
		}

		cont = n-m;
		for (int i = 1; i <= n; ++i)
			if ( arr[ i ] )
			{
				cout << i;
				
				arr[ i ] = false;
				--cont;
				
				if( cont )
					cout << " ";
			}
		cout << endl;
	}
	return 0;
}