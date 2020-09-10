#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
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

ll gauss( ll n, bool impar )
{
	if ( impar )
		return n*n;

	return n*(n+1);
}



ll l_b( ll num, ll aux, bool impar )
{
	ll i = 0, j = md, m;

	while( j-i > 1 )
	{
		m = i + (j-i)/2;
		if ( gauss(m, impar) > num )
			j = m;
		else
			i = m;
	}

	return i;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	ll casos, l, r, l_pancakes, r_pancakes, aux;

	cin >> casos;
	for( int numero_caso = 1; numero_caso <= casos; ++numero_caso )
	{
		cin >> l >> r;

		if ( r > l )
		{
			aux = l_b( r-l, 1 );
			r -= gauss( aux, 1 );
		}
		else
		{
			aux = l_b( l-r, 1 );
			l -= gauss( aux, 1 );
		}

		bool flag = false;
		if( r > l )
			flag = true;

		l_pancakes = l_b( l, aux, flag == false );
		r_pancakes = l_b( r, aux, flag == true );

		l -= gauss( l_pancakes, aux, flag == false );
		r -= gauss( r_pancakes, aux, flag == true );
		

		cout << "Case #" << numero_caso << ": ";
		cout << pancake-1 << ' ' << l << ' ' << r << endl;
	}

	return 0;
}