#include <bits/stdc++.h>

using namespace std;

int arr[ 105 ];

int find_min( int ini, int n )
{
	int mini = 900; int pos;
	for (int i = ini; i < n; ++i)
		if ( arr[ i ] < mini )
		{
			mini = arr[ i ];
			pos = i;
		}

	return pos;
}

int main()
{
	int n, q;
	cin >> q;
	while( q-- )
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		int pos = 0;
		while( pos < n-1 )
		{
			int k = find_min( pos, n );

			if ( k == pos )
			{
				++pos;
				continue;
			}
			
			int aux = arr[ k ];
			for (int i = k; i > pos; --i)
				arr[ i ] = arr[ i-1 ];
			arr[ pos ] = aux;
			pos = k;
		}

		cout << arr[ 0 ];
		for (int i = 1; i < n; ++i)
			cout << " " << arr[ i ];
		cout << '\n';
	}
	return 0;
}