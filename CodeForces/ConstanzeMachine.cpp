#include <bits/stdc++.h>
#define mod 1000000007
#define maxn 100005

using namespace std;
typedef long long ll;

ll fibo[ maxn ];

int main()
{
	string cad;

	fibo[ 0 ] = fibo[ 1 ] = 1;
	for (int i = 2; i < maxn; ++i)
		fibo[ i ] = (fibo[ i-1 ] + fibo[ i-2 ]) % mod;

	cin >> cad;
	int n = cad.size();

	int pos = 0;
	ll cont, ans = 1; 
	while( pos < n)
	{
		if ( cad[ pos ] == 'm' || cad[ pos ] == 'w' )
		{
			cout << "0\n";
			return 0;
		}

		if ( cad[ pos ] != 'u' && cad[ pos ] != 'n' )
			++pos;
		else
		{	
			cont = 1; ++pos;
			while( pos < n && cad[ pos ] == cad[ pos-1 ] )
			{
				++cont; ++pos;
			}
			ans = (ans * fibo[ cont ]) % mod;
		}
	}

	cout << ans << '\n';
}