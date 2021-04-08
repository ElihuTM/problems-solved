#include <iostream>
#define maxn 100007

using namespace std;

int arr[ maxn ];

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int casos, n, pos;
	string cad;

	cin >> casos;
	while( casos-- )
	{
		cin >> n >> cad;

		arr[ n-1 ] = -1;
		for (int i = n-2; i >= 0 ; --i)
		{
			if ( cad[ i ] < cad[ i+1 ])
				arr[ i ] = i+2;
			else
			{
				pos = arr[ i+1 ] - 1;
				while( pos != -1 and cad[ i ] >= cad[ pos ])
				{
					pos = arr[ pos ];
					if( pos != -1)
						pos--;
				}

				if ( pos!=-1)
					pos++;
				arr[ i ] = pos;
					
			}
		}

		for (int i = 0; i < n; ++i){
			cout << arr[ i ];
			if ( i < n-1 )
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}