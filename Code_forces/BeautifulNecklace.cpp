#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 100005
#define md(x) (((x%mod) + mod) % mod)
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

int acum[ maxn ][ 4 ];
int n;

int binary_search( int i, int j ) {
	int m;
	bool flag = false;
	int mn = n+n;
	int mx = 0;

	for (int k = 0; k < 4; ++k)
		{
			mx = max( mx, acum[ n ][ k ] );
			mn = min( mn, acum[ n ][ k ] );
		}

	if( mx == mn ) return n / 4;

	for (int i = 4; i <= n; ++i) {
		mn = n+n;
		mx = 0;

		for (int k = 0; k < 4; ++k)
		{
			mx = max( mx, acum[ i ][ k ] - acum[ i-4 ][ k ] );
			mn = min( mn, acum[ i ][ k ] - acum[ i-4 ][ k ] );
		}

		if( mx == mn )
			flag = true;
	}

	if( !flag ) return -1;

	while( j-i > 1 ) {
		m = i + (j-i)/2;

		if( is_pos( m ) )
			i = m;
		else
			j = m;
	}
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	map< char, int> idx;
	string cad;

	idx[ 'R' ] = 0; idx[ 'G' ] = 1;
	idx[ 'B' ] = 2; idx[ 'Y' ] = 3;

	cin >> cad;
	n = cad.size();
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 4; ++j)
			acum[ i ][ j ] += acum[ i-1 ][ j ];
		
		++acum[ i ][ idx[ cad[ i-1 ] ] ];
	}

	pii ans( 5, 0 );
	pii pos( 1, 1 );
	for (int i = 1f; i <= n; ++i)
	{
		for (int j = i; j <= n; ++j)
		{


			if( mx-mn <= ans.ff ) {
				if( mx-mn == ans.ff and j-i+1 <= ans.ss )
					continue;

				ans = make_pair( mx-mn, j-i+1  );
				pos = make_pair( i, j );
			}
		}
	}

	/*
	for (int j = 0; j < 4; ++j) {
		for (int i = 0; i <= n; ++i)
			cout <<  acum[ i ][ j ] << " ";
		cout << endl;
	}*/
	cout << ans.ff << " " << ans.ss << endl;
	cout << pos.ff << " " << pos.ss << endl;
	return 0;
}