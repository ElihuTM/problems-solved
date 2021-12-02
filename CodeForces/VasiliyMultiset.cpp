#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 100005
#define OK (1L<<32)-1
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
	
	int n, k;
	char op;
	map <ll, ll> multi;
	map <ll, ll>::iterator it;

	cin >> n;
	while( n-- )
	{
		cin >> op >> k;
		if( op == '+' )
			++multi[ k ];
		else if( op == '-' ) {
			it = multi.find( k );

			if( it->ss == 1 )
				multi.erase( it );
			else
				it->ss--;
		}
		else {
			ll rev = OK&(~k);
			ll last = (OK+1) >> 1;
			ll ans = 0;
			
			for ( auto c: multi )
				cout << c.ff << " ";
			cout << endl;
			while( rev )
			{
				it = multi.lower_bound( rev );
				if( it->ss == rev )
					ans = max( ans, rev^k );
				else if( it != multi.begin() ) {
					--it;
					ans = max( ans, it->ss^k );
				}

				if( last&rev )
					rev ^= last;

				last >>= 1;
			}
			cout << ans << endl;
		}
	}

	return 0;
}