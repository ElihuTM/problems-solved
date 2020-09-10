#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 2017
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

int arr[ maxn ];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	unordered_map<int,int> cont;
	int t, n;
	ll ans;

	cin >> t;
	while( t-- )
	{
		cin >> n; ans = 0;
		for (int i = 0; i < n; ++i)
			cin >> arr[ i ];

		for (int i = 0; i < n-1; ++i)
		{
			cont.clear();
			for (int j = i+1; j < n; ++j)
				cont[ arr[ j ] ]++;

			for (int j = i+1; j < n; ++j)
			{
				cont[ arr[ j ] ]--;
				ans += cont[ arr[ j ] + arr[ j ] - arr[ i ] ];				
			}
		}

		cout << ans << endl;
	}
	return 0;
}
