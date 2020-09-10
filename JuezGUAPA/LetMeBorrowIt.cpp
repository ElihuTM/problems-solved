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

ll memo[ maxn ];

ll dp( int n )
{
	if( n < 0 )
		return 0;

	if( n == 0 )
		return 1;

	if( ~memo[ n ] )
		return memo[ n ];

	return memo[ n ] = dp( n-1 ) + dp( n-2 );
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	

	memset( memo, -1, sizeof( memo ));
	
	int t, n;
	cin >> t;

	while( t-- )
	{
		

		cin >> n;
		cout << dp( n ) << endl;
	}
	return 0;
}
