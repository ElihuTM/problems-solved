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

int arr[ maxn ];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n, m, t, x, y;

	cin >> n >> m;

	cin >> t;
	for (int i = 0; i < t; ++i ) {
		cin >> x >> y;
		++arr[ y ];
	}

	for (int i = 1; i <= 300; ++i)
		arr[ i ] = max( arr[ i ], arr[ i-1 ] );
	
	for (int i = 301; i <= m; ++i)
		arr[ i ] = max( arr[ i ] + arr[ i-301 ], arr[ i-1 ] );

	cout << arr[ m ] << endl;


	return 0;
}