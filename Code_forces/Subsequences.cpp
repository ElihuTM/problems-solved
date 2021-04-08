#include <bits/stdc++.h>
#define maxn 100005
#define forn(a,n) for( int i = a; i < n; ++i )

using namespace std;
typedef long long ll;

int arr[ maxn ];
ll ans[ maxn ];
ll ft[ maxn ]; 

inline int LSOne( int n )
{
	return n&(-n);
}

inline ll query( int a )
{
	ll ans = 0;
	for( int i = a; i; i-=LSOne(i) )
		ans += ft[ i ];
	return ans;
}

inline void update( int a, ll value )
{
	for( int i = a; i < maxn; i+=LSOne(i) )
		ft[ i ] += value;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, lim;
	ll cont;

	cin >> n >> lim;
	
	forn(0,n)
	{
		cin >> arr[ i ];
		ans[ i ] = 1;
	}

	for( int k=0; k < lim; ++k )
	{
		memset( ft, 0, sizeof ft );
		forn(0,n)
		{
			cont = query( arr[ i ]-1 );
			update( arr[ i ], ans[ i ] );
			ans[ i ] = cont;
		}
	}
	
	ll answer = 0;
	forn(0,n)
		answer += ans[ i ];

	cout << answer <<'\n';
	return 0;
}

/*
1 2 3 5 4	1:
1 1 1 1 1	2:
0 1	2 3	3	3:
0 0	1 3 3	4:
			5:
				
*/
