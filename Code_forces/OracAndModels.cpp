#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
#define sz(a) s.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vi arr;
	vi ans;

	ll t, n;
	cin >> t;
	while( t-- )
	{
		cin >> n;
		arr = vi( n+1 );
		ans = vi( n+1, 1);
		for (int i = 1; i <= n; ++i)
			cin >> arr[ i ];

		ans[ 1 ] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = i+i; j <= n; j+=i )
				if ( arr[ i ] < arr[ j ] && ans[ i ]+1 > ans[ j ] )
					ans[ j ] = ans[ i ]+1;

		int answer = 1;
		for (int i = 1; i <= n; ++i)
			answer = max( answer, ans[ i ] );
		cout << answer << endl;
	}

	return 0;
}
