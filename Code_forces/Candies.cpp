#include <bits/stdc++.h>

using namespace std;

inline int LSOne( int n ) {
	return n&(-n);
}

inline bool is_sum( int x ){
	++x;
	return ( x - LSOne( x ) == 0 );
}

int resp( int n )
{
	int pot = 4;

	while( (pot-1) <= n )
	{
		if ( n % (pot-1) == 0 )
			return n / (pot-1);

		pot <<= 1;
	}

	return 1;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int t,n;
	cin >> t;
	while( t-- )
	{
		cin >> n;		
		cout << resp( n ) << '\n';
	}

	return 0;
}