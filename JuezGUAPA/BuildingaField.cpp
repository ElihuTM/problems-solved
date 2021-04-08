#include <bits/stdc++.h>
#define maxn 200007

using namespace std;
typedef long long ll;

ll arr[ maxn ];

int _lower_bound(int i, int j, int value)
{
	int ini = i;
	int m;

	while( j-i > 1)
	{
		m = i + (j-i)/2;

		if ( arr[ m ] - arr[ ini ] >= value)
			j = m;
		else
			i = m;
	}

	return j;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n;
	ll a,b;
	cin >> n;

	arr[ 0 ] = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[ i ];
		arr[ i ] += arr[ i-1 ];
	}

	for (int m = 0; m < n-3; ++m)
	{
		for (int i = m+1; i < n-2 ; ++i)
		{
			//cout << m << " " << i <<" :\n";
			if ( arr[ i ] - arr[ m ] > arr[ n ] - arr[ i ] + arr[ m ] )
				break;

			if( (arr[ n ] - 2*(arr[ i ] - arr[ m ])) & 1)
				break;

			a = arr[ i ] - arr[ m ];
			b = (arr[ n ] - 2*(arr[ i ] - arr[ m ]) ) / 2;

			int is = _lower_bound( m, n, arr[n]/2 );

			if ( arr[ is ] - arr[ m ] != arr[n]/2 )
				break;

			int j = _lower_bound( i, n, b );
			if ( arr[ j ] - arr[ i ] != b)
				
				continue;

			int k = _lower_bound( j, n, a );
			if ( arr[ k ] - arr[ j ] != a)
				continue;

			cout << "Y\n";
			return 0;
		}
	}

	cout << "N\n";
	return 0;
}