#include <bits/stdc++.h>
#define maxn 105

using namespace std; 

int arr[ maxn ];
bool type[ maxn ];

int main( )
{
	int t, n, s;

	cin >> t;
	while( t-- )
	{
		cin >> n >> s;

		int t1 = maxn, t2 = maxn;
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		for (int i = 0; i < n; ++i)
		{
			cin >> type[ i ];

			if ( type[ i ] )
				t1 = min( t1, arr[ i ] );
			else
				t2 = min( t2, arr[ i ] );
		}

		if ( s+t1+t2 <= 100 )
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}