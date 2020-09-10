#include <bits/stdc++.h>
#define maxn 107

using namespace std;

int p[ maxn ];
int c[ maxn ];

bool is_possible( int n )
{
	int antp = -1, antc = -1;

	for (int i = 0; i < n; ++i)
	{
		if ( p[ i ] < c[ i ])
			return false;

		if ( antp > p[ i ] )
			return false;

		if ( antc > c[ i ] )
			return false;

		if ( p[ i ]-antp < c[ i ]-antc )
			return false;

		antp = p[ i ];
		antc = c[ i ];
	}

	return true;
}

int main()
{
	int n, t;
	cin >> t;

	while( t-- )
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> p[ i ] >> c[ i ];

		if ( is_possible( n ) )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}	
	