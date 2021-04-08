#include <bits/stdc++.h>
#define endl '\n'
#define maxn 1003

using namespace std;
typedef long long ll;

struct pii
{
	ll ff;
	int ss;

	bool operator < ( const pii &p) const
	{
		return ( ff < p.ff || (ff == p.ff && ss > p.ss) );
	}
};
typedef vector< pii > vi;

int n, m;
vi a;
vi b;
pii memo[ maxn ][ maxn ];

pii m_p( ll q, ll w )
{
	pii aux;
	aux.ff = q;
	aux.ss = w;

	return aux;
}

pii dp( int i, int j )
{
	if( i == n || j == m )
		return m_p(0,0);
	
	if( memo[ i ][ j ].ff != -1 )
		return memo[ i ][ j ];

	pii ans = max( dp( i+1, j), dp( i, j+1) );
	if( a[ i ].ss == b[ j ].ss )
	{
		pii aux = dp( i+1, j+1 );
		aux.ff += a[ i ].ff + b[ j ].ff;
		++aux.ss;
		
		ans = max( aux, ans );
	}

	return memo[ i ][ j ] = ans;
}

int main()
{
	map <string, int> _hash;
	int t, val;
	string nom, sys;
	
	cin >> t;
	while( t-- )
	{
		_hash.clear();

		cin >> n;
		a.resize( n );
		for( int i = 0; i < n; ++i )
		{
			cin >> nom >> sys >> val;
			if( _hash.find( sys ) == _hash.end() )
				_hash.insert( make_pair(sys,_hash.size()+1) );

			a[ i ].ss = _hash[ sys ];
			a[ i ].ff = val;
		}
		
		cin >> m;
		b.resize( m );
		for( int i = 0; i < m; ++i )
		{
			cin >> nom >> sys >> val;
			if( _hash.find( sys ) == _hash.end() )
				_hash.insert( make_pair(sys,_hash.size()+1) );

			b[ i ].ss = _hash[ sys ];
			b[ i ].ff = val;
		}
		
		for( int i = 0; i < n; ++i )
			for( int j = 0; j < m; ++j )
				memo[ i ][ j ] = m_p( -1, -1 );

		pii ans = dp( 0, 0 );
		cout << ans.ff << " " << ans.ss << endl;
	}
	return 0;
}
