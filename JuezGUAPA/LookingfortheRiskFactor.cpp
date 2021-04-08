#include <bits/stdc++.h>
#define maxn 100007
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

bool tocado[ maxn ];
bool criba[ maxn ];
vector< pii > ans;
vector< ll > p;
int ft[ maxn ];
int limit;

struct query
{
	int n;
	int k;
	int pos;

	bool operator < (const query &x) const
	{
		return (( x.k < k ) || ( x.k == k && x.n < n ) || ( x.k == k && x.n == n && x.pos < pos ));
	}
};

vector< query > answers;

void llena()
{
	memset(criba, 1, sizeof criba);
	criba[ 0 ] = criba[ 1 ] = false;

	p.push_back( 2 );
	for (int i = 4; i < maxn; i += 2)
		criba[ i ] = false;

	for ( ll i = 3; i < maxn; i +=2 )
		if ( criba[ i ])
		{
			for ( ll j = i*i; j < maxn; j += i)
				criba[ j ] = false;
			p.push_back( i );
		}
}

inline int LSOne( int n )
{
	return n & -n;
}

void adjust( int k, int value )
{
	for (; k < maxn; k += LSOne( k ))
		ft[ k ] += value;
}

int consultar( int a )
{
	int tot = 0;
	while( a )
	{
		tot += ft[ a ];
		a -= LSOne( a );
	}

	return tot;
}

int upper_bound( int i, int j, int value )
{
	int m;
	while( j-i > 1 )
	{
		m = i + (j-i)/2;
		if ( p[ m ] > value )
			j = m;
		else
			i = m;
	}

	return j;
}

int cont( int n, int k )
{
	int it = upper_bound( -1, p.size()-1, k );

	for (int i = it; p[i] < limit; ++i)
		for (int j = p[ i ]; j < maxn; j += p[ i ] )
			if ( !tocado[ j ])
			{
				adjust( j, -1);
				tocado[ j ] = true;
			}
		
	limit = p[ it ];

	return consultar( n );
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	memset( ft, 0, sizeof (ft) );
	memset( tocado, false, sizeof tocado );
	llena();

	query aux;
	limit = 100001;
	int q, parcial;

	for (int i = 2; i < maxn; ++i)
		adjust( i, 1 );	

	cin >> q;
	for (int i = 0; i < q ; ++i)
	{
		cin >> aux.n >> aux. k;
		aux.pos = i;

		answers.push_back( aux );
	}
	sort( answers.begin(), answers.end() );

	for (int i = 0; i < q; ++i)
	{
		parcial = cont( answers[ i ].n, answers[ i ].k );
		ans.emplace_back( answers[ i ].pos, parcial ); 
	}

	sort( ans.begin(), ans.end() );

	for (int i = 0; i < q; ++i)
		cout << ans[ i ].second << endl;

	return 0;
}