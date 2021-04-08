#include <bits/stdc++.h>
#define maxn 10005

using namespace std;
typedef long long ll;

int arr[ maxn ];
int t, n;
ll k;

bool is_pos( int m )
{
	ll sum = 0;
	for( int i = 0; i < n; ++i )
		sum += arr[ i ] / m;

	return sum >= k;
}

int l_b( int i, int j )
{
	int m;
	while( j-i > 1 )
	{
		m = i + (j-i)/2;

		if( is_pos( m ) )
			i = m;
		else
			j = m;
	}
	return i;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie( 0 );

	cin >> t;
	while( t-- )
	{
		cin >> n >> k;

		for( int i = 0; i < n; ++i )
			cin >> arr[ i ];

		cout << l_b( 1, 1000000007 ) << '\n';
	}
	return 0;
}
