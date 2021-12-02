#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int l_b( int i, int j, ll value, ll n )
{
	int m;
	while( j-i > 1 )
	{
		m = i + ((j-i)>>1);
		if( (ll)ceil( log2( m ) )*(ll)n > value )
			j = m;
		else
			i = m;
	}

	return i;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, a;
	ll I;
	cin >> n >> I;
	map< int, int > arr;
	map< int, int >::iterator it;

	for( int i = 0; i < n; ++i )
	{
		cin >> a;
		++arr[ a ];
	}

	int len = arr.size();
	vector <int> elem;

	for( it = arr.begin(); it != arr.end(); ++it )
		elem.push_back( it->second );
	
	int dif = l_b( 0, len+1, I*8, n);
	//cout << dif << "  ------\n";

	int ans, nid = elem.size() - dif;
	ll sum_l = 0, sum_r = 0;

	for( int i = 0; i < nid; ++i )
		sum_l += elem[ i ];
	
	ans = sum_l;
	for( int i = 0; i < nid; ++i )
	{
		sum_l -= elem[ nid-1-i ];
		sum_r += elem[ elem.size()-i-1 ];
		
		if( sum_l + sum_r < ans )
			ans = sum_l + sum_r;
	}

	cout << ans << '\n';

	return 0;
}
