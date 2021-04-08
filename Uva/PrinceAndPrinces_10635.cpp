#include <bits/stdc++.h>
#define maxn 62503

using namespace std;
typedef vector <int> vi;

int arr[ maxn ];
vi v;

int lower_bound( vi x, int value )
{
	int i = -1, j = x.size()-1, m;
	
	while( j-i > 1)
	{
		m = i + (j-i)/2;
		if( value <= x[ m ] )
			j = m;
		else
			i = m;
	}

	return j;
}

int LIS( )
{
	vi ans;
	ans.push_back( v[ 0 ] );

	for( int i = 1; i < v.size(); ++i )
	{
		if( v[ i ] <= ans[ 0 ] )
			ans[ 0 ] = v[ i ];
		else if( v[ i ] >= ans.back() )
			ans.push_back( v[ i ] );
		else
		{
			int ind = lower_bound( ans, v[ i ] );
			ans[ ind ] = v[ i ];
		}
	}

	return ans.size();
}

int main()
{
	int caso, n, p, q, a;

	cin >> caso;
	for( int it =1; it <= caso; ++it )
	{
		cin >> n >> p >> q; ++p; ++q;
		
		v.clear();
		memset( arr, -1, sizeof arr );
		for( int i = 0; i < p; ++i )
		{
			cin >> a;
			arr[ a ] = i;
		}
		
		for( int i = 0; i < q; ++i )
		{
			cin >> a;
			if( ~arr[ a ] )
				v.push_back( arr[ a ] );
		}

		cout << "Case " << it << ": " << LIS() << endl;
	}

	return 0;
}
