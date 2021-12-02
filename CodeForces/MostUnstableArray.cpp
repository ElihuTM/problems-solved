#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
#define sz(a) s.size()
#define endl '\n'
#define forn(i,n)  for ( int i = 0; i < n; ++i )

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	ll t, n, k;
	cin >> t;
	while( t-- )
	{
		cin >> n >> k; 
		if ( n == 1)
			cout << 0 << endl;
		else if ( n==2 )
			cout << k << endl;
		else
			cout << 2*k << endl;
	}

	return 0;
}