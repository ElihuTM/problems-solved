#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 188888851
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

ll exp[ maxn ];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	exp[ 0 ] = 0;
	exp[ 1 ] = 1;
	for( int i = 2; i < maxn; ++i )
		exp[ i ] = md( exp[ i-1 ] * 2 );


	return 0;
}
