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

vector<string> keyboard;
const int n = 3, m = 9;

int near( pii a, pii b )
{
	if( abs(a.ff-b.ff) > 1 or abs(a.ss-b.ss) > 1)
		return false;

	return true;


}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	vector< pii > pos( 30 );
	keyboard.push_back( "abcdefghi" );
	keyboard.push_back( "jklmnopqr" );
	keyboard.push_back( "stuvwxyz#" );

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 9; ++j)
		{
			if( i == 2 and j == 8 )
				continue;

			pos[ keyboard[ i ][ j ] - 'a' ] = pii( i, j );
		//	cout << keyboard[ i ][ j ] << " " << i << " " << j << endl;			
		}

	int q;
	string a, b;

	cin >> q;
	while( q-- ){
		cin >> a >> b;

		if( a == b )
			cout << 1 << endl;
		else if( a.size() == b.size() )
		{
			bool flag = true;
			for (int i = 0; i < a.size(); ++i)
				if( !near( pos[ a[ i ] - 'a' ], pos[ b[ i ]- 'a' ]) )
				{
					flag = false;
					break;
				}

			if( flag )
				cout << 2 << endl;
			else
				cout << 3 << endl;
		}
		else
			cout << 3 << endl;

	}
	return 0;
}