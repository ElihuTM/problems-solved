#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 60
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

int calcular( int n, int m, int a, int b, int mat[ maxn ][ maxn ] )
{
	int ans = n*m, aux;
	for (int i = a; i <= n; ++i)
	{
		for (int j = b; j <= m; ++j)
		{
			aux = mat[ i ][ j ];
			aux -= mat[ i-a ][ j ];
			aux -= mat[ i ][ j-b ];
			aux += mat[ i-a ][ j-b ];
			
			ans = min ( ans, aux );
		}

	}
	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n, m, a, b;
	int mat[ maxn ][ maxn ];
	memset( mat, 0, sizeof( mat ));

	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> mat[ i ][ j ];

			mat[ i ][ j ] += mat[ i-1 ][ j ];
			mat[ i ][ j ] += mat[ i ][ j-1 ];
			mat[ i ][ j ] -= mat[ i-1 ][ j-1 ];
		}
	}
	cin >> a >> b;

	int ans1 = calcular( n, m, a, b, mat );
	int ans2 = calcular( n, m, b, a, mat );

	cout << min( ans1, ans2 ) << endl;
	return 0;
}