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

struct ari
{
	int a, b;
	ll	value,
		weight,
		children;

	ari( ) { }
	ari( int a, int b, ll value, ll weight, ll children ) {
		this->a = a;
		this->b = b;
		this->value = value;
		this->weight = weight;
		this->children = children;
	}

	bool operator < ( const ari &p ) const {

		if( value < p.value )
			return true;

		if( value == p.value )
			if ( (weight/2) * children < ( p.weight / 2 ) * p.children )
				return true;

		return false;
	}
};


vvi lista;
vi parent;
vi children;
vector <ari> aristas;

int dfs( int u, int father= -1 ) {
	
	parent[ u ] = father;
	int ans = (lista[ u ].size() == 1);

	for (int i = 0; i < lista[ u ].size(); ++i)
	{
		int v = lista[ u ][ i ];
		if ( v != father )
			ans += dfs( v, u );
	}

	return children[ u ] = ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t, n, a, b , w;
	ll s;

	cin >> t;
	while( t-- ) {
		cin >> n >> s;

		aristas.resize( n-1 );
		parent.resize( n, -1 );
		children.resize( n, 0 );
		priority_queue <ari> weights;
		lista = vvi( n );

		for (int i = 0; i < n-1; ++i)
		{
			cin >> a >> b >> w; --a; --b;
			lista[ a ].push_back( b );
			lista[ b ].push_back( a );
			aristas[ i ] = ari( a, b, w, w, 1 ); 
		}

		dfs( 0 );

		ll sum = 0;
		ll cont = 0;

		for (int i = 0; i < n-1; ++i)
		{
			ari aux = aristas[ i ];
			if( parent[ aux.a ] == aux.b )
				aristas[ i ].children = children[ aux.a ];
			else
				aristas[ i ].children = children[ aux.b ];

			aristas[ i ].value = aristas[ i ].weight * aristas[ i ].children;

			while( aristas[ i ].value > s ) {
				aristas[ i ].weight /= 2;
				aristas[ i ].value = aristas[ i ].weight * aristas[ i ].children;
				++cont;
			}

			sum += aristas[ i ].value;
			weights.push( aristas[ i ] );
		}

		while( sum > s ) {
			ari aux = weights.top(); weights.pop();
			
			//cout << aux.a << " " << aux.b << endl;
			sum -= aux.value;

			aux.weight /= 2;
			aux.value = aux.weight * aux.children;

			sum += aux.value;
			weights.push( aux );
			++cont;
		}

		cout << cont << endl;
	}

	return 0;
}