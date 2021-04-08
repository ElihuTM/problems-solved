#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair < ll, ll > pii;

vector< pii > pintores;
vector< ll > memo;
ll n, k;

int _upper_bound( ll value )
{
	int i = -1, j = k-1, m;

	if ( value > pintores.back().first )
		return k;

	while( j-i > 1 )
	{
		m = i + (j-i)/2;
		if ( pintores[ m ].first > value )
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
	
	ll ini, fin, dist;
	int ind;

	///////////////////////////// INPUT ///////////////////77
	cin >> n >> k;
	pintores = vector< pii >( k );
	memo = vector< ll >( k+1, -1 );

	for (int i = 0; i < k; ++i)
	{
		cin >> ini >> fin;
		pintores[ i ] = make_pair( ini, fin );
	}

	sort( pintores.begin(), pintores.end() );
	
	////////////////////////////// BOTTOM UP ////////////////////////////
	memo[ k ] = 0;
	for (int p = k-1; p >= 0 ; --p)
	{
		dist = pintores[ p ].second - pintores[ p ].first + 1;
		ind = _upper_bound( pintores[ p ].second );

		memo[ p ] = max( memo[ p+1 ], memo[ ind ] + dist );
	}

	//////////////////////////////// ANSWER /////////////////////////
	cout << n - memo[ 0 ] << endl;
	return 0;
}