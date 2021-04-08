#include <bits/stdc++.h>
#define maxn 100000
#define p_b(a) push_back(a)

using namespace std;
typedef long long ll;

bitset <maxn> criba;
vector <ll> p;

void llena()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = false;

	for( int i = 4; i < maxn; i+=2 )
		criba[ i ] = false;
	
	p.p_b(2);
	for( ll i = 3; i < maxn; i+=2 )
		if( criba[ i ] )
		{
			p.p_b(i);
			for( ll j = i*i; j < maxn; j += i )
				criba[ j ] = false;
		}
}

int divs( ll n )
{
	ll pp = 2, cont = 0;
	int ans = 1, pow;

	while( pp*pp <= n )
	{
		pow = 0;
		while( n%pp == 0 )
		{
			++pow;
			n /= pp;
		}
		
		ans *= (pow+1);
		pp = p[ ++cont ];
	}

	if( n != 1 )
		ans *= 2;
	
	return ans;
}

int main()
{
	llena();
	vector<int> di;
	vector<ll> num;

	int maxi = 0, it = 1;
	ll trian = 1;
	while( maxi <= 1000 )
	{
		int aux = divs( trian );
		if( aux > maxi )
		{
			maxi = aux;
			di.p_b( aux );
			num.p_b( trian );
		}
		trian += ( ++it );
	}
	
	int t, x;
	cin >> t;

	while( t-- )
	{
		cin >> x;
		for( int i = 0; i < num.size(); ++i )
			if( di[ i ] > x )
			{
				cout << num[ i ] << '\n';
				break;
			}
	}

	return 0;
}
