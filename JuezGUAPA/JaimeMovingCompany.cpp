#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 986444681
#define maxn 200015
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

ll fact[ maxn ];
ll rev_fact[ maxn ];

set <int> read_input()
{
	stringstream ss;
	set <int> ans;
	string cad;
	int a;

	getline(cin, cad);
	ss << cad;
	while( ss >> a )
		ans.insert( a );

	return ans;
}

ll fast_pow ( ll x, ll exp )
{
	ll ans = 1;
	while( exp )
	{
		if( exp & 1 )
			ans = ( ans * x ) % mod;

		x = ( x * x ) % mod;
		exp >>= 1;
	}
	return ans;
}

ll comb( ll n, ll k )
{
	if( k < 0 )
		return 1;

	ll ans = fact[ n ];
	ans = ( ans * fast_pow( fact[ k ], mod-2 ) ) % mod;
	ans = ( ans * fast_pow( fact[ n-k ], mod-2 )) % mod;

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t, N, K, s, b;
	string algo;

	fact[ 0 ] = 1;
	for (int i = 1; i < maxn; ++i)
		fact[ i ] = ( i * fact[ i-1 ] ) % mod;

	cin >> t;
	while( t-- )
	{
		cin >> N >> K;
		cin >> s >> b;
		getline(cin, algo );
		set <int> super = read_input();
		set <int> boss = read_input();

		for( int i = 1; i <= N; ++i )
		{
			int box_super, box_boss;
			if( super.find( i ) != super.end() )
				box_super = s;
			else
				box_super = 0;

			if( boss.find( i ) != boss.end() )
				box_boss = b;
			else
				box_boss = 0;

			K -= max( box_super, box_boss );
		}

		if( K < 0 )
			cout << 0 << endl;
		else
			cout << comb( N+K-1, N-1 ) << endl;
	}

	return 0;
}
