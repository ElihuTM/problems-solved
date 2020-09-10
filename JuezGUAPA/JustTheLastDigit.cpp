#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 500
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) a.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

vvi mat;
vvi cop;
vvi ans;
int n;

void rest( vi &a, vi &b )
{
	for (int i = 0; i < n; ++i)
		a[ i ] = (a[ i ] - b[ i ] + 10) % 10;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	string cad;

	cin >> n;

	mat.assign( n, vi( n ) );
	cop.assign( n, vi( n ) );
	ans.assign( n, vi( n, 0 ) );
	
	for (int i = 0; i < n; ++i)
	{
		cin >> cad;
		for (int j = 0; j < sz(cad); ++j)
			mat[ i ][ j ] = cop[ i ][ j ] = cad[ j ]-'0';
	}

	for (int i = n-2; i >= 0 ; --i)
		for (int j = 0; j < n; ++j)
			if ( cop[ i ][ j ] != 0 )
			{
				ans[ i ][ j ] = 1;
				cop[ i ][ j ] = 0;

				rest( cop[ i ], mat[ j ] );
			}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << ans[ i ][ j ];
		cout << endl;
	}
	return 0;
}