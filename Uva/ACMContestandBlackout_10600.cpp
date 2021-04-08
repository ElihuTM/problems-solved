#include <bits/stdc++.h>
#define maxn 105
#define ff first
#define ss second

using namespace std;
typedef pair <int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;

struct ari
{
    int a, b, c;

    bool operator < ( const ari &p ) const
    {
        return c < p.c;
    }
};

int padre[ maxn ];
int n, m;
vii ant;
vvii lista;

void bfs( int u )
{
    ant = vii( n, pii(-1,0) );
    queue <int> q;

    ant[ u ] = pii( u, 0 ); q.push( u );
    while( !q.empty() )
    {
        int u = q.front(); q.pop();

        for (int i = 0; i < lista[ u ].size(); ++i)
        {
            int v = lista[ u ][ i ].ff, d = lista[ u ][ i ].ss;

            if ( ant[ v ].ff == -1 )
            {
                ant[ v ] = pii( u, d );
                q.push( v );
            }
        }
    }
}

int padrote( int u )
{
    return u == padre[ u ] ? u : padre[ u ] = padrote( padre[ u ] );
}

bool union_find( int a, int b )
{
    int c = padrote( a ), d = padrote( b );

    if ( c == d ) return false;

    if ( rand()&1)
        padre[ c ] = d;
    else
        padre[ d ] = c;

    return true;
}

int main()
{
    int t;

    cin >> t;
    while( t-- )
    {
        cin >> n >> m;

        vector<ari> aristas( m );
        vector<ari> residuo;
        lista = vvii( n );

        for (int i = 0; i < n; ++i)
            padre[ i ] = i;

        for (int i = 0; i < m; ++i)
            cin >> aristas[ i ].a >> aristas[ i ].b >> aristas[ i ].c;
        
        sort( aristas.begin(), aristas.end() );
        int MST = 0;

        for (int i = 0; i < m; ++i)
        {
            int a = aristas[ i ].a - 1;
            int b = aristas[ i ].b - 1;
            int c = aristas[ i ].c;
            if ( union_find( a, b ) )
            {
                lista[ a ].emplace_back( b,c );
                lista[ b ].emplace_back( a,c );
                MST += c;
            }
            else
                residuo.push_back( aristas[ i ] );
        }

        int MST2 = 999999999;
        for (int i = 0; i < residuo.size(); ++i)
        {
            int a = residuo[ i ].a - 1;
            int b = residuo[ i ].b - 1;
            int c = residuo[ i ].c;

            bfs( a );
            int mayor = 0;

            while( b != a )
            {
                mayor = max( mayor, ant[ b ].ss );
                b = ant[ b ].ff;
            }

            MST2 = min( MST2, MST - mayor + c );
        }
        cout << MST << " " << MST2 << '\n';
    }
}