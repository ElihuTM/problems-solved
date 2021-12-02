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

vpii sqrt_decos;
vi arr;
int n, m;

void build( ) {
	int pos = 0;

	while( pos*m < n ) {
		sqrt_decos.emplace_back( pos*m, 0 );
		for (int i = pos*m; i < (pos+1)*m; ++i)
		{
			if( i == maxn )
				break;

			if ( arr[ i ] > sqrt_decos[ pos ].ss )
				sqrt_decos[ pos ] = make_pair( i, arr[ i ] ); 
		}
		++pos;
	}
}

void update( int x, int value ) {
	arr[ x ] += value;
	ll pos = x / m;

	sqrt_decos[ pos ] = make_pair( pos*m, 0 );
	for (int i = (pos*m); i < (pos+1)*m; ++i)
	{
		if( i == maxn )
			break;

		if ( arr[ i ] > sqrt_decos[ pos ].ss )
			sqrt_decos[ pos ] = make_pair( i, arr[ i ] ); 
	}
}

pii query( ) {
	pii ans( 0, 0 );
	for (int i = 0; i < sqrt_decos.size(); ++i)
		if( sqrt_decos[ i ].ss >= ans.ss )
			ans = sqrt_decos[ i ];
	return ans;
}

bool is_pos( ) {
	pii cuad, rec1, rec2;

	cuad = query( );
	update( cuad.ff, -4 );
	rec1 = query( );
	update( rec1.ff, -2 );
	rec2 = query( );

	update( cuad.ff, 4 );
	update( rec1.ff, 2 );

	if( cuad.ss >= 4 and rec1.ss >= 2 and rec2.ss >= 2 )
		return true;

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);	
	
	int t, x, q;
	char op;
	
	cin >> n;
		
	m = sqrt( maxn );
	arr.assign( maxn, 0 );
	sqrt_decos.clear();

	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		arr[ x ]++;		
	}
	build();

	cin >> q;
	while( q-- ) {
		cin >> op >> x;

		if( op == '+' )
			update( x, 1 );
		else
			update( x, -1 );

		if( is_pos() )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}