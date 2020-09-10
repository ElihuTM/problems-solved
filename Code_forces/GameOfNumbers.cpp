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

bool f( string a, string b ) {
	int mn = min( a.size(), b.size() );

	for (int i = 0; i < mn; ++i) {
		if( a[ i ] > b[ i ] )
			return true;
		else if( a[ i ] < b[ i ] )
			return false;
	}

	return a.size() < b.size();
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n;
	cin >> n;
	vector<string> num(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> num[ i ];
		sort( num[ i ].rbegin(), num[ i ].rend() );
	}

	sort( num.begin(), num.end(), f );

	for (int i = 0; i < n; ++i)
		cout << num[ i ];
	cout << endl;
	return 0;
}