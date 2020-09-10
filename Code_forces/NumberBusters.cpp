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
	
	ll a, b, w, x, c;
	scanf("%lld %lld %lld %lld %lld", &a, &b, &w, &x, &c );

	ll cont = 0;

	//printf("a b w x c\n");
	while( c > a )
	{
		--c;
		if( b < x )
		{
			--a;
			b += w;
		}
		b -= x;

		++cont;
		//printf("%lld %lld %lld %lld %lld\n", a, b, w, x, c);
	}

	printf("%lld\n", cont);
	return 0;
}