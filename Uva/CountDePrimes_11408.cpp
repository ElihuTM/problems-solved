#include <bits/stdc++.h>
#define maxn 5000004

using namespace std;
typedef long long ll;

int arr[ maxn ];
int criba[ maxn ];

bool is_pePrime( ll n )
{
	ll pp = criba[ n ], sum = 0;
	
	while( n > 1 )
	{
		sum += pp;

		while( criba[ n ] == pp )
			n /= criba[ n ];

		pp = criba[ n ];
	}
	
	return criba[ sum ] == sum;
}

void llena()
{
	memset( arr, 0, sizeof arr );
	memset( criba, -1, sizeof criba );

	criba[ 0 ] = criba[ 1 ] = 1;
	for( int i = 2; i < maxn; i+=2 )
		criba[ i ] = 2;

	for( ll i = 3; i < maxn; i += 2 )
		if( criba[ i ] == -1 )
		{
			criba[ i ] = i;
			for( ll j = i*i; j < maxn; j += i )
				if( criba[ j ] == -1 )
					criba[ j ] = i;
		}

	for( int  i = 2; i < maxn; ++i )
	{
		arr[ i ] = arr[ i-1 ];
		if( is_pePrime( i ) )
			++arr[ i ];
	}
}

int main()
{
	int a, b;
	llena();

	cin >> a;
	//for( int i = 1; i < 25; ++i )
	//	cout << i << " : " << arr[ i ] << endl;

	while( a )
	{
		cin >> b;
		cout << arr[ b ] - arr[ a-1 ] << '\n';
		cin >> a;
	}
	return 0;
}
