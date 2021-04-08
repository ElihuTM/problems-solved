#include <bits/stdc++.h>
#define maxn 1000005L

using namespace std;
typedef long long ll;

bitset <maxn> criba;
int arr[ maxn ];
vector <ll> p;

void llena()
{
	criba.set();
	memset( arr, 0, sizeof arr );

	for( ll i = 5; i < maxn; i += 4 )
		if( criba[ i ] )
		{
			for( ll j = i*i; j < maxn; j += i )
				criba[ j ] = 0;
			p.push_back( i );
		}
	
	int len = p.size();
	for( int i = 0; i < len; ++i )
		for( int  j = i; j < len; ++j )
		{
			if( p[ i ]*p[ j ] >= maxn )
				break;

			arr[ p[ i ]*p[ j ] ] = 1;
		}
	
	for( int i = 1; i < maxn; ++i )
		arr[ i ] += arr[ i-1 ];
}

int main()
{
	llena();
	int a;

	cin >> a;
	while( a )
	{
		cout << a << " " << arr[ a ] << endl;
		cin >> a;
	}
	return 0;
}
