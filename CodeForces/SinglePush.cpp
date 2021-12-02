#include <bits/stdc++.h>
#define maxn 100007

using namespace std;

int a[ maxn ];
int b[ maxn ];
int dif[ maxn ];

int main()
{
	int q, n;
	cin >> q;
	while( q-- )
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[ i ];

		for (int i = 0; i < n; ++i)
			cin >> b[ i ];

		bool is_pos = true;
		for (int i = 0; i < n; ++i)
		{
			if ( a[ i ] > b[ i ] )
			{
				is_pos = false;
				break;
			}
			dif[ i ] = b[ i ] - a[ i ];
		}

		if( is_pos )
		{
			int ini = -1, fin = 0;
			for (int i = 0; i < n; ++i)
			{
				if ( dif[ i ] != 0 && ini == -1 )
					ini = i;

				if( dif[ i ] != 0 )
					fin = i;
			}

			for (int i = ini; i < fin; ++i)
				if ( dif[ i ] != dif[ i+1 ] )
				{
					is_pos = false;
					break;
				}
			
			if ( is_pos )
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
			cout << "NO\n";

	}
	return 0;	
}