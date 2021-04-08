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
	
	int n;
	cin >> n;

	vi days( n+5, 100 );
	for (int i = 0; i < n; ++i)
	{
		cin >> days[ i ];
	}

	int answer = 1;
	int max_temperature = max( days[ 0 ], days[ 2 ] );

	for (int i = 0; i < n; ++i)
	{
		if( max(days[ i ], days[ i+2 ]) < max_temperature )
		{
			max_temperature = max( days[ i ], days[ i+2 ] );
			answer = i+1;
		}
	}

	cout << answer << " " << max_temperature << endl;
	return 0;
}