#include <bits/stdc++.h>
#define ff first
#define ss second
#define maxn 800002
#define l(p) p<<1
#define r(p) (p<<1)+1
#define mid(i,j) ((i+j)>>1)
#define m_p(a,b) make_pair(a,b)

using namespace std;
typedef pair <int,int> pii;

pii arbol[ maxn ];
int cont[ maxn ];

void build( int p, int i, int j )
{
	if( i == j )
	{
		arbol[ p ] = m_p( cont[ p ], 0 );
		return;
	}

	build( l(p), i, mid(i,j) );
	build( r(p), mid(i,j)+1, j );

	int sum = arbol[ l(p) ].ff + arbol[ r(p) ].ff;
	arbol[ p ].ff = cont[ p ] + sum;
	arbol[ p ].ss = arbol[ l(p) ].ss + arbol[ r(p) ].ss + sum;
}

int  q( int p, int i, int j, int v )
{
	if( v < 0 || cont[ p ] == v)
		return 0;

	if( arbol[ p ].ff == v )
		return arbol[ p ].ss;
	
	if( arbol[ p ].ff < v )
		return 99999999;
	
	int suml = arbol[ l(p) ].ff + arbol[ l(p) ].ss; 
	int sumr = arbol[ r(p) ].ff + arbol[ r(p) ].ss; 
	int vl = v - arbol[ l(p) ].ff - cont[ p ];
	int vr = v - arbol[ r(p) ].ff - cont[ p ];

		int ans = sumr + q( l(p), i, mid(i,j), vr ) + (vr > 0 ? vr : 0);
	ans = min(ans, suml + q( r(p), mid(i,j)+1, j, vl ) + (vl > 0 ? vl : 0) );

	ans = min(ans, q( l(p), i, mid(i,j), v ) );
	ans = min(ans, q( r(p), mid(i,j)+1, j, v ) );

	return ans;
}

int main()
{
	int n, k, x;
	
	cin >> n >> k;
	for( int i = 0; i < n; ++i )
	{
		cin >> x;
		++cont[ x ];
	}
	
	build( 1, 0, 100002 );

	cout << q( 1,0, 100002, k ) << '\n';
}
