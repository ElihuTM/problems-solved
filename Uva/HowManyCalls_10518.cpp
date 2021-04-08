#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct mat
{
	ll a, b, c, d, mod;

	mat operator * ( mat &p )
	{
		mat ans;
		ans.a = (a*p.a + b*p.c) % mod;
		ans.b = (a*p.b + b*p.d) % mod;
		ans.c = (c*p.a + d*p.c) % mod;
		ans.d = (c*p.b + d*p.d) % mod;
		ans.mod = mod;
		return ans;
	}
};

inline mat id( int m )
{
	mat aux;
	aux.a = aux.d = 1;
	aux.b = aux.c = 0;
	aux.mod = m;
	return aux;
}

inline mat base( int m )
{
	mat aux;
	aux.a = aux.b = aux. c = 1;
	aux.d = 0;
	aux.mod = m;
	return aux;
}

mat f_p( mat x, ll exp, int mod )
{
	mat ans = id( mod );
	while( exp )
	{
		if( exp&1 )
			ans = ans*x;

		x = x*x;
		exp >>= 1;
	}

	return ans;
}

ll fib( ll n, int mod )
{
	if( n == 0 )
		return 1;
	
	mat aux = base( mod );
	mat ans = f_p( aux, n-1, mod );

	return ans.a;
}

int main()
{
	ll n, b, caso = 0;
	cin >> n >> b;

	while( n || b )
	{
		cout << "Case " << ++caso << ": " << n << " " << b << " " << (2*fib( n+1, b )-1+b) % b << '\n';
		cin >> n >> b;
	}
	return 0;
}
