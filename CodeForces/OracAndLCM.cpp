#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
#define p_b(a) push_back(a)
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
	int n;

	ll maxgcd;
	cin >> n;

	vi arr( n );
	vi gcd( n );

	cin >> arr[ 0 ]; maxgcd = arr[ 0 ];
	for (int i = 1; i < n; ++i)
	{
		cin >> arr[ i ];
		maxgcd = __gcd( maxgcd, arr[ i ] );
	}

	for (int i = 0; i < n; ++i)
		arr[ i ] /= maxgcd;

	if ( n == 1)
	{
		cout << arr[ 0 ] << endl;
		return 0;
	}

	gcd[ n-1 ] = arr[ n-1 ];
	for (int i = n-2; i >= 0; --i)
		gcd[ i ] = __gcd( arr[ i ], gcd[ i+1 ] );

	ll answer = arr[ 0 ]*(gcd[ 1 ]/gcd[ 0 ]);
	for (int i = 0; i < n-1; ++i)
	{
		answer = __gcd( answer, arr[ i ]*(gcd[ i+1 ]/gcd[ i ]) );
	}
	//answer = __gcd( answer, arr[ n-1 ] );

	cout << maxgcd*answer << endl;
	
	/*
	for (int i = 0; i < n; ++i)
	{
		printf("%2lld ",arr[ i ] );
	}
	printf("\n");
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			cout << "   ";
		}

		for (int j = i+1; j < n; ++j)
		{
			printf("%2lld ", __gcd( arr[ i ], arr[ j ] ));
			//cout << __gcd( arr[ i ], arr[ j ] ) << ' ';
		}
		cout << endl;
	}*/

	return 0;
}
