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

bool caso1( ll a, ll n )
{
	if( a%n == 0 )
		return true;

	return false;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll n, m, a, b;
	cin >> n >> m >> a;

	b = (n*m)-a;
	if( a%n == 0 or a%m == 0 or b%n == 0 or b%m == 0)
		cout << 1 << endl;
	else
	{
		ll lim = sqrt( a );

		for( ll i = 1; i<=lim; ++i )
		{
			if( a%i == 0 )
			{
				if( (i <= n and a/i <= m) or (i<=m and a/i <= n) )
				{
					cout << 2 << endl;
					return 0;
				}
			}
		}


		lim = sqrt( b );
		for( ll i = 1; i<=lim; ++i )
		{
			if( b%i == 0 )
			{
				if( (i <= n and b/i <= m) or (i<=m and b/i <= n) )
				{
					cout << 2 << endl;
					return 0;
				}
			}
		}

		cout << 3 << endl;
	}

	return 0;
}