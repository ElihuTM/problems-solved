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

struct prob
{
	ld rock;
	ld scissor;
	ld paper;

	prob( ) {  }
	prob( ld a, ld b, ld c ) : rock( a ), scissor( b ), paper( c ) { } 
};

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int r, s, p;
	cin >> r >> s >> p;

	prob ans = dp( r, s, p );
	return 0;
}