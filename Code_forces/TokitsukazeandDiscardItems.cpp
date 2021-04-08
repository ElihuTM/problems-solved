#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector <ll> vi;

vi arr;

int u_b( int i, int j, ll value)

int main ()
{
	int n, m, k;
	arr = vi( m );

	for( int i = 0; i < m; ++i )
		cin >> arr[ i ];
	
	int it = 0;
	int cuenta = k, pos, enc;
	int sum = 0;

	while( sum < m )
	{
		pos = u_b( 0, m, cuenta );

		if( pos == -1 )
			cuenta += k;
		else
		{
			enc = pos - sum + 1;
			cuenta += enc;
		}

		++it;
	}

	cout << it << '\n';
	return 0;
}
