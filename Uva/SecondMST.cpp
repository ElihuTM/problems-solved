    #include <bits/stdc++.h>
    #define maxn 1000000
    #define right(p) (p<<1)+1
    #define left(p) p<<1
    #define mid(a,b) (a+b)>>1
     
    using namespace std;
    typedef long long ll;
    typedef pair < int, int > pii;
    typedef vector <int> vi;
    typedef vector < pii > vii;
    typedef vector < vii > vvii;
     
    struct ari
    {
    	int a,b;
    	int peso;
     
    	bool operator < (const ari & p )const
    	{
    		return peso < p.peso;
    	}
    };
     
    typedef vector< ari > va; 
    int n, m;
     
    ari m_a ( int a, int b, int c )
    {
    	ari aux;
    	aux.a = a;
    	aux.b = b;
    	aux.peso = c;
     
    	return aux;
    }
     
     
    /////////Union find //////////////
    int padre[ maxn ];
     
    ////////// MST //////////////////
    va edges;
    va MST;
    va resi;
     
    ///////// LCA ///////////////////
    vvii lista;
     
    vi ar_min; /// arbol de minimos
    vi arbol; // segment
    vi dad; // su padre
    vi dist; // costo hasta la raiz
    vi prim; // primera vez en aparecer
    vi sec; // la secuencia del camino
    vi pr; //profundidad del nodo
     
    void dfs( int u, ll p )
    {
    	if( prim[ u ] == -1)
    		prim[ u ] = sec.size();
    	sec.push_back( u );
    	
    	int len = lista[ u ].size();
    	for( int i = 0; i < len; ++i )
    	{
    		int v = lista[ u ][ i ].first;
    		int b = lista[ u ][ i ].second;
     
    		if( pr[ v ] == -1 )
    		{
    			dad[ v ] = u;
     
    			dist.push_back( b );
    			pr[ v ] = pr[ u ] + 1;
     
    			dfs( v, b );
    			sec.push_back( u );
    		}
    	}
     
    	dist.push_back( p );
    }
     
    void build_min( int p, int i, int j )
    {
    	if ( i == j )
    	{
    		ar_min[ p ] = dist[ i ];
    		return;
    	}
     
    	build_min( left(p), i, mid( i,j) );
    	build_min( right(p), (mid(i,j))+1, j );
     
    	ar_min[ p ] = ( ar_min[ left(p) ] > ar_min[ right(p) ] ? ar_min[ left(p) ] : ar_min[ right(p) ] );
    }
     
    void build_segment( int p, int i, int j )
    {
    	if( i == j )
    	{
    		arbol[ p ] = sec[ i ];
    		return;
    	}
    	
    	build_segment( left(p), i, mid(i,j) );
    	build_segment( right(p), (mid(i,j))+1, j );
    	
    	int d1 = pr[ arbol[ left(p) ] ];
    	int d2 = pr[ arbol[ right(p)] ];
     
    	arbol[ p ] = ( d1 < d2 ? arbol[ left(p) ] : arbol[ right(p) ] ); 
    }
     
    int query( int p, int i, int j, int a, int b )
    {
    	if(  i > b || j < a )
    		return -1;
     
    	if( i >= a && j <= b )
    		return arbol[ p ];
     
    	int d1 = query( left(p), i , mid(i,j), a, b );
    	int d2 = query( right(p), (mid(i,j))+1, j, a, b );
     
    	if( d1 == -1 ) return d2;
     
    	if( d2 == -1 ) return d1;
     
    	return (pr[ d1 ] < pr[ d2 ] ? d1 : d2 );
    }
     
    int w_min( int p, int i, int j, int a, int b )
    {
    	if(  i > b || j < a )
    		return -1;
     
    	if( i >= a && j <= b )
    		return ar_min[ p ];
     
    	int d1 = query( left(p), i , mid(i,j), a, b );
    	int d2 = query( right(p), (mid(i,j))+1, j, a, b );
     
    	if( d1 == -1 ) return d2;
     
    	if( d2 == -1 ) return d1;
     
    	return ( d1 > d2 ? d1 : d2 );
    }
     
    void build()
    {
    	dad = vi( n, -1 );
    	prim = vi ( n, -1 );	
    	pr = vi( n, -1);
     
    	pr[ 0 ] = 0;
    	dfs( 0, 0 );
     
    	arbol = vi( 6*sec.size() );
    	ar_min = vi( 6*dist.size() );
     
    	build_min( 1, 0, dist.size()-1 );
    	build_segment( 1, 0, sec.size()-1 );
    }
     
    inline int LCA( int a, int b )
    {
    	if ( prim[ a ] > prim[ b ] )
    		swap( a,b );
     
    	return query( 1, 0, sec.size()-1, prim[ a ],prim[ b ] );
    }
     
    inline int par_mini( int a, int b )
    {
    	if( prim[ b ] - 1 == prim[ a ] )
    		return 999999999;
     
    	return  w_min( 1, 0, dist.size(), prim[ a ], prim[ b ]-1 );
    }
     
    int min_ari( int a, int b )
    {
    	int c = LCA( a, b );
    	
    	int d1 = par_mini( c, a );
    	int d2 = par_mini( c, b );
    	
    	return ( d1 > d2 ? d1 : d2 );
    }
     
    ///////////////////// Union find ((((((((((((((((((((((((((((((((((((((((((((((
    int padrote( int a )
    {
    	if( a == padre[ a ] )
    		return a;
     
    	return padre[ a ] = padrote( padre[ a ] ); 
    }
     
    bool union_find( int a, int b )
    {
    	int c = padrote( a );
    	int d = padrote( b );
     
    	if( c == d ) return false;
     
    	if( rand() & 1 )
    		padre[ c ] = d;
    	else
    		padre[ d ] = c;
     
    	return true;
    }
     
     
    int main()
    {
    	int a,b,c;
     
    	cin >> n >> m;
    	
    	edges = va( m );
    	lista = vvii( n );
    	for( int i = 0; i < n; ++i )
    		padre[ i ] = i;
     
    	for( int i = 0; i < m; ++i )
    	{
    		cin >> a >> b >> c;
    		edges[ i ] = m_a( a-1, b-1, c );
    	}
     
    	sort( edges.begin(), edges.end() );
    	int len = 0, it = 0;
    	ll ans = 0;
     
    	for ( it = 0; i < edges.size(); ++it)
    	{
    		if( union_find( edges[ it ].a, edges[ it ].b ) )
    		{
    			++len;
    			ans += edges[ it ].peso;
    			MST.push_back( edges[ it ] );
    		}
    		else
    			resi.push_back( edges[ it ] );
    		++it;
    	}
    	
    	cout << ans << " ";
     
     
    	//////////////// aqui va lo chido /////
    	//
    	//pasar a lista
    	
    	//cout << endl;
    	for( int i = 0; i < len; ++i )
    	{
    		a = MST[ i ].a;
    		b = MST[ i ].b;
    		c = MST[ i ].peso;
     
    		lista[ a ].push_back( make_pair( b, c) );
    		lista[ b ].push_back( make_pair( a, c) );
    	}
     
    	build( );
     
    	if( resi.empty() )
    	{
    		cout << "-1\n";
    		return 0;
    	}
    	
    	ll ans2 = 99999999999999999;
    	for( int i = 0; i < resi.size(); ++i )
    	{
    		ll d1 = min_ari( resi[ i ].a, resi[ i ].b );
    		ans2 = ( ans2 < ans-d1+resi[ i ].peso ? ans2 : ans-d1+resi[ i ].peso);
    	}
     
    	cout << ans2 << endl;
    	return 0;
    }