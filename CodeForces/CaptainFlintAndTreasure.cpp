#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 100005
#define md(x) (((x%mod) + mod) % mod)
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


int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n;
	cin >> n;
	vi a( n );
	vi b( n );
	vi padres( n, 0);

	for (int i = 0; i < n; ++i) {
		cin >> a[ i ];
	}

	for (int i = 0; i < n; ++i) {
		cin >> b[ i ];
		if( b[ i ] != -1 ) {
			b[ i ]--;
			padres[ b[ i ] ]++;
		}
	}

	queue <int> sig;
	stack <int> neg;

	for (int i = 0; i < n; ++i) {
		if ( padres[ i ] == 0 )
			sig.push( i );
	}

	ll ans = 0;
	vi permutation;
	while( !sig.empty() ) {
		int front = sig.front(); sig.pop();

		if( a[ front ] < 0 ) {
			neg.push( front );
		}
		else {
			ans += a[ front ];
			if( b[ front ] != -1)
				a[ b[ front ] ] += a[ front ];
			permutation.push_back( front );
		}

		if( b[ front ] != -1 ) {
			padres[ b[ front ] ]--;
			if ( padres[ b[ front ] ] == 0 )
				sig.push( b[ front ] );
		}
	}

	while( !neg.empty() ) {
		int front = neg.top(); neg.pop();

		ans += a[ front ];
		permutation.push_back( front );
	}

	cout << ans << endl;
	for (int i = 0; i < permutation.size(); ++i)
		cout << permutation[ i ]+1 << " ";
	cout << endl;
	return 0;
}