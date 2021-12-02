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

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	vvi costo = vvi( 27, vi(27, mod) );
	ll n, e,answer = 0;
	string a, b, ans;
	char c, d;	

	cin >> a;
	cin >> b;
	cin >> n;

	ans = a;
	for (int i = 0; i < n; ++i)
	{
		cin >> c >> d >> e;
		costo[ c - 'a' ][ d - 'a' ] = min( costo[ c-'a' ][ d-'a' ], e );
	}

	for (int i = 0; i < 27; ++i)
		costo[ i ][ i ] = 0;

	for (int k = 0; k < 27; k++)
		for (int i = 0; i < 27; i++)
			for (int j = 0; j < 27; j++)
				costo[i][j] = min( costo[i][j], costo[i][k] + costo[k][j]);

	if( a.size() != b.size() )
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < ans.size(); ++i)
	{
		int price = mod;
		for( int j = 0; j < 27; ++j )
			if( costo[ a[ i ]-'a' ][ j ] + costo[ b[ i ] -'a' ][ j ] < price )
			{
				price = costo[ a[ i ]-'a' ][ j ] + costo[ b[ i ] -'a' ][ j ];
				ans[ i ] = j + 'a';
			}
		
		answer += price;
	}

	if( answer < mod )
		cout << answer << endl << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}