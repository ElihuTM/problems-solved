#include <bits/stdc++.h>
#define inf 999999999
#define ff first
#define ss second
#define maxn 110

using namespace std;
typedef pair <int,int> pii;
typedef vector<int> vi;

int residuo[ maxn ][ maxn ];
vi anterior;
int s, t, f, mf, n, m;

void augment( int u, int minEdge )
{
	if( u == s )
	{
		f = minEdge;
		return;
	}

	if( anterior[ u ] != -1 )
	{
		augment( anterior[ u ], min( minEdge, residuo[ anterior[ u ] ][ u ] ) );
		residuo[ anterior[ u ] ][ u ] -= f;
		residuo[ u ][ anterior[ u ] ] += f;
	}
}

/*
inline bool is_pos( int u, int v )
{
	if ( (u == 0 && v == 1) || (v == 0 && u == 1) )
		return true;

	if ( (u == 2*(n-1) && v == 2*n-1) || (v == 2*(n-1) && u == 2*n-1) )
		return true;

	if ( residuo[ u ][ v ] != 0 )
		return true;

	return false;
}*/

int main()
{
	vi dist;
	int a, b, c;

	cin >> n >> m;

	while( n || m )
	{

		s = 0, t = 2*(n-1); mf = 0;
		for (int i = 0; i < 2*n; ++i)
			for (int j = 0; j < 2*n; ++j)
				residuo[ i ][ j ] = 0;

		for (int i = 0; i < n-2; ++i)
		{
			cin >> a >> b; --a;
			//printf("del %d al %d le damos %d\n", 2*a, 2*a+1, b );
			//printf("del %d al %d le damos %d\n", 2*a+1, 2*a, b );
			//printf("\n");

			residuo[ 2*a ][ 2*a + 1 ] += b;
			residuo[ 2*a + 1 ][ 2*a ] += b;
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b >> c;
			--a; --b;
			int a1 = a*2, b1 = b*2, a2 = ( a == 0 || a == n-1 ? a1 : a1+1 ), b2 = ( b == 0 || b == n-1 ? b1 : b1+1 );

			//printf("del %d al %d le damos %d\n", b2, a1, c );
			//printf("del %d al %d le damos %d\n", a2, b1, c );
			//printf("\n");
			residuo[ b2 ][ a1 ] += c;
			residuo[ a2 ][ b1 ] += c;
		}
		/*
		printf("lvl  ");
		for (int i = 0; i < 2*n; ++i)
		{
			printf("%3d", i);
		}
		printf("\n");
		for (int i = 0; i < 2*n+4; ++i)
		{
			printf("___");
		}
		printf("\n");
		for (int i = 0; i < 2*n; ++i)
		{
			printf("%3d| ", i);
			for (int j = 0; j < 2*n; ++j)
			{
				printf("%3d", residuo[ i ][ j ] );
			}
			cout << endl;
		}*/

		/*
		while(1)
		{
			dist.assign( 2*n, inf ); dist[ s ] = 0;
			anterior.assign( 2*n, -1 );
			f = 0;

			priority_queue <pii, vector<pii>, greater<pii> > pq; pq.push( pii(0,s) );
			while( !pq.empty() )
			{
				int d = pq.top().ff, u = pq.top().ss; pq.pop();
				if ( d > dist[ u ] ) continue;

				for (int v = 0; v < 2*n; ++v)
				{
					int dv = residuo[ u ][ v ];
					if ( dv && dist[ u ] + dv < dist[ v ] )
					{
						anterior[ v ] = u;
						dist[ v ] = dist[ u ] + dv;
						pq.push( pii( dist[ v ], v ) );
					}
				}
			}

			augment( t, inf );
			if ( f == 0) break;
			mf += f;
		}*/

		while(1)
		{
			f = 0;
			anterior.assign( 2*n, -1 );
			dist.assign( 2*n, inf );
			queue <int> next;
			next.push( s );

			while( !next.empty() )
			{
				int u = next.front(); next.pop();

				//if ( u == t ) break;

				for (int v = 0; v < 2*n; ++v)
					if ( residuo[ u ][ v ] > 0 && dist[ v ] == inf )
					{
						dist[ v ] = dist[ u ] + 1;
						anterior[ v ] = u;
						next.push( v );
					}
			}

			augment( t, inf );
			if( !f ) break;
			mf += f;
		}

		cout << mf << '\n';

		cin >> n >> m;
	}

	return 0;
}