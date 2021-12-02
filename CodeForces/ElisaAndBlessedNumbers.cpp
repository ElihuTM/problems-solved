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

vector< string > nums;
int n, m;

bool have_sbstr( ll num ) {
	
	string cad;
	while( num ) {
		cad.push_back( (num%10) + '0' );
		num /= 10;
	}
	reverse( cad.begin(), cad.end() );

	for (int i = 0; i < m; ++i ){
		int pos = cad.find( nums[ i ] );
		if( pos >= 0 and pos < cad.size() )
			return true;
	}

	//cout << cad << endl;
	return false;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	

	cin >> m;
	string cad;

	nums.resize( m );
	for (int i = 0; i < m; ++i) {
		cin >> cad;
		nums[ i ] = cad;
	}

	cin >> n;
	ll pos = 0, num = 1;
	while( pos < n ) {
		if( !have_sbstr( num ) )
			++pos;

		++num;
	}

	cout << num-1 << endl;
	return 0;
}