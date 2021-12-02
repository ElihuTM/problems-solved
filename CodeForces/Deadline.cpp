#include <bits/stdc++.h>
#define mid(i,j) ((i+j)>>1)

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

ll n, d;

inline ll f( ll x ) {
	return x + ((d+x)/(x+1));
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int t;
	cin >> t;
	while( t-- ) {
		
		cin >> n >> d;
		ll sqrt1 = floor( sqrt( d ) - 1 );
		ll sqrt2 = ceil( sqrt( d ) -1 );
		ll answer;
		answer = min( f(sqrt1 ), f(sqrt2 ) );

		if( answer > n )
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}
