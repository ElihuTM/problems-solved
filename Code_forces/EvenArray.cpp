#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

vi arr;
int n;

int find_other( int i )
{
	for (int j = i+1; j < n; ++j)
		if ( (arr[ j ] % 2 != j % 2) and (arr[ j ] % 2 == i % 2) ) 
			return j;
	return -1;
}

int ans( )
{
	int ansi = 0;
	for (int i = 0; i < n; ++i)
	{
		if( arr[ i ] % 2 == i % 2 )
			continue;

		int j = find_other( i );

		if( j == -1 )
			return -1;

		swap( arr[ i ], arr[ j ] );
		++ansi;
	}

	return ansi;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		arr.resize( n );
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		cout << ans( ) << endl;
	}

	return 0;
}
