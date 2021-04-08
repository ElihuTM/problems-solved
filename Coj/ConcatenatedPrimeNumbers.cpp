#include <bits/stdc++.h>
#define maxn 100000000

using namespace std;
typedef long long ll;

bitset <maxn> criba;
//vector < ll > p;

void llenar()
{
	criba.set();

	criba[ 0 ] = criba[ 1 ] = 0;
	for (int i = 4; i < maxn; i+= 2)
		criba[ i ] = false;

	//p.push_back( 2 );
	for (ll i = 3; i < maxn; i+=2)
		if ( criba[ i ] )
		{
			//p.push_back( i );
			for ( ll j = i*i; j < maxn; j+=i )
				criba[ j ] = false;
		}
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	llenar();

	int k, len, par;
	string cad;
	bool ban;

	while( cin >> k >> cad )
	{
		len = cad.size();
		ban = true;

		for (int i = 0; i < len; i+=k )
		{
			par = 0;
			for (int j = 0; j < k; ++j)
				par = (par*10) + cad[ i+j ] - '0' ;
			
			if ( !criba[ par ] )
			{
				ban = false;
				break;
			}
		}

		if ( ban )
			cout << ":)\n";
		else
			cout << ":(\n";
	}
	return 0;
}