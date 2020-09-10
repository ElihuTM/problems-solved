#include <bits/stdc++.h>
#define mod 1000000000
#define maxn 1005

using namespace std;
typedef long long ll;

ll arr[ maxn ];
ll n, d;

bool is_pos( ll day )
{
	for (int i = 0; i < n; ++i)
	{
		if ( day > d )
			return false;

		if ( day % arr[ i ] != 0 )
			day += arr[ i ] - ( day % arr[ i ] );
	}
	
	return ( day <= d );
}

ll u_b( ll i, ll j )
{
	if ( is_pos( j ) )
		return j+1;

	ll m;
	while( j - i > 1 )
	{
		m = i + (j-i)/2;

		//cout << m << ": " << is_pos( m ) << endl;

		if ( is_pos( m ) )
			i = m;
		else
			j = m;
	}
	return j;
}

int main()
{
	int t;

	cin >> t;
	for ( int c = 1; c <= t; ++c)
	{
		cin >> n >> d;
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		cout << "Case #" << c << ": " << u_b( 0, d )-1 << '\n';
	}
}