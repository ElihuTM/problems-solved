#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 1000005
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
 
/*
int memo[ maxn ];
 
bool dp( int n ) {
	if( n == 1 )
		return true;
 
	if( ~memo[ n ] )
		return memo[ n ];
 
	int lim = sqrt( n );
	for (int i = 1; i <= lim; ++i)
		if( dp(n-i) == false )
			return memo[ n ] = true;
	
	return memo[ n ] = false;
}
*/
 
int main()
{	
	freopen("nim.in", "r", stdin);
	freopen("nim.out", "w", stdout);

	ll n, pos = 2, raiz = 1, next_raiz = 2;
	//memset( memo, -1, sizeof( memo ));
	//set <ll> perdedores;
 
	cin >> n;
	//perdedores.insert( 2 );
	while( pos < n ) {
 
		while( next_raiz*next_raiz < pos )
			++next_raiz;
		
		pos += raiz + 1;
		if( next_raiz * next_raiz <= pos ) {
			raiz = next_raiz;
			++pos;
		}
		//perdedores.insert( pos );
	}
	/*
	for (int i = 2; i < n; ++i)
	{
		bool op1 = dp( i );
		bool op2 = (perdedores.find( i ) == perdedores.end());
 
		if( op1 != op2 )
			cout << i << "es diferente" << endl;
	}
	*/
 
	if( pos == n )
		cout << "LOSE\n";
	else
		cout << "WIN\n";
	
	fclose( stdin );
	fclose( stdout );
	return 0;
}