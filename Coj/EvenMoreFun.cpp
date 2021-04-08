//4139
#include <iostream>
#define maxn 303
#define endl '\n'

using namespace std;
//typedef long long ll;

int vect1[ maxn ]; ////////////// NO TOCAR
int vect2[ maxn ]; ///////////// NO TOCAR X2

int mat[ maxn ][ maxn ];
int mau[ maxn ][ maxn ];
int precalculo_hori[ maxn ][ maxn ];
int precalculo_vert[ maxn ][ maxn ];
int hori1[ maxn ][ maxn ];
int hori2[ maxn ][ maxn ];
int hori3[ maxn ][ maxn ];
int hori4[ maxn ][ maxn ];

int maxsum( int n, int* arr, int* vect )
{
	int sub_sum;
	sub_sum = vect[ 1 ] = arr[ 1 ];

	for (int i = 2; i <= n; ++i)
	{
		if (sub_sum < 0)
			sub_sum = 0;

		sub_sum += arr[ i ];
		vect[ i ] = max(sub_sum, arr[ i ]);
	}

	for (int i = 2; i <= n; ++i)
		vect[ i ] = max( vect[ i ], vect[ i-1 ] );
	
	return vect[ n ];
}

int revsum( int n, int* arr, int* vect )
{
	int sub_sum;
	sub_sum = vect[ n ] = arr[ n ];

	for (int i = n-1; i > 0; --i)
	{
		if (sub_sum < 0)
			sub_sum = 0;

		sub_sum += arr[ i ];
		vect[ i ] = max(sub_sum, arr[ i ]);
	}

	for (int i = n-1; i > 0; --i)
		vect[ i ] = max( vect[ i ], vect[ i+1 ] );
	
	return vect[ 1 ];
}

void precalcular( int n, int m, int precalculo[ maxn ][ maxn ] )
{
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			vect2[ j ] = 0;

		for (int j = i; j <= n; ++j)
		{
			for (int k = 1; k <= m; ++k)
				vect2[ k ] += mau[ j ][ k ];

			precalculo[ i ][ j ] = maxsum( m, vect2, vect1 );
		}
	}

	for (int i = n-1; i > 0; --i)
		for (int j = i+1; j <= n; ++j)
		{
			precalculo[ i ][ j ] = max(precalculo[ i+1 ][ j ], precalculo[ i ][ j ]);
			precalculo[ i ][ j ] = max(precalculo[ i ][ j-1 ], precalculo[ i ][ j ]);
		}
}

void cmp( int* arr, int* vect, bool pos, int n )
{
	if ( pos )
		for (int i = 1; i <= n; ++i)
			arr[ i ] = vect[ i ];
	else
		for (int i = 1; i <= n; ++i)
			arr[ i ] = max( arr[ i ], vect[ i ]);
}

void precalcular_horis( int n, int m )
{

	////////////////////  DIAGONALES DE ARRIBA ///////////////////
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
			vect2[ j ] = 0;
		for (int j = i; j <= n ; ++j)
		{
			for (int k = 1; k <= m; ++k)
				vect2[ k ] += mau[ j ][ k ];
			
			maxsum( m, vect2, vect1 );
			cmp( hori1[ j ], vect1, (i==1), m );

			revsum( m, vect2, vect1 );
			cmp( hori2[ j ], vect1, (i==1), m );
		}
		
	}

	for (int i = 2; i <= m; ++i)
	{
		hori1[ 1 ][ i ] = max( hori1[ 1 ][ i ], hori1[ 1 ][ i-1 ] );
		hori2[ 1 ][ m-i+1 ] = max( hori2[ 1 ][ m-i+1 ], hori2[ 1 ][ m-i+2 ] );
	}
	for (int i = 2; i <= n; ++i)
	{
		hori1[ i ][ 1 ] = max( hori1[ i ][ 1 ], hori1[ i-1 ][ 1 ] );
		hori2[ i ][ m ] = max( hori2[ i ][ m ], hori2[ i-1 ][ m ] );
	}

	for (int i = 2; i <= n; ++i)
		for (int j = 2; j <= m; ++j)
		{
			hori1[ i ][ j ] = max( hori1[ i ][ j ], hori1[ i-1 ][ j ] );
			hori1[ i ][ j ] = max( hori1[ i ][ j ], hori1[ i ][ j-1 ] );

			hori2[ i ][ m-j+1 ] = max( hori2[ i ][ m-j+1 ], hori2[ i-1 ][ m-j+1 ] );
			hori2[ i ][ m-j+1 ] = max( hori2[ i ][ m-j+1 ], hori2[ i ][ m-j+2 ] );
		}

	/////////////////// DIAGONALES DE ABAJO ///////////////////////////

	for (int i = n; i > 0; --i)
	{

		for (int j = 1; j <= m; ++j)
			vect2[ j ] = 0;
		for (int j = i; j > 0 ; --j)
		{
			for (int k = 1; k <= m; ++k)
				vect2[ k ] += mau[ j ][ k ];
			
			maxsum( m, vect2, vect1 );
			cmp( hori4[ j ], vect1, (i==n), m );

			revsum( m, vect2, vect1 );
			cmp( hori3[ j ], vect1, (i==n), m );
		}
	}


	for (int i = 2; i <= m; ++i)
	{
		hori4[ n ][ i ] = max( hori4[ n ][ i ], hori4[ n ][ i-1 ] );
		hori3[ n ][ m-i+1 ] = max( hori3[ n ][ m-i+1 ], hori3[ n ][ m-i+2 ] );
	}
	for (int i = n-1; i > 0 ; --i)
	{
		hori4[ i ][ 1 ] = max( hori4[ i ][ 1 ], hori4[ i+1 ][ 1 ] );
		hori3[ i ][ m ] = max( hori3[ i ][ m ], hori3[ i+1 ][ m ] );
	}

	for (int i = n-1; i > 0; --i)
		for (int j = 2; j <= m; ++j)
		{
			hori4[ i ][ j ] = max( hori4[ i ][ j ], hori4[ i+1 ][ j ] );
			hori4[ i ][ j ] = max( hori4[ i ][ j ], hori4[ i ][ j-1 ] );

			hori3[ i ][ m-j+1 ] = max( hori3[ i ][ m-j+1 ], hori3[ i+1 ][ m-j+1 ] );
			hori3[ i ][ m-j+1 ] = max( hori3[ i ][ m-j+1 ], hori3[ i ][ m-j+2 ] );
		}
}
int EvenMoreFun( int n, int m, int k )
{
	if ( k == 1)
		return max(precalculo_hori[ 1 ][ n ], precalculo_vert[ 1 ][ n ]);
	
	if ( k == 2)
	{
		int ans = -2000000;
		for (int i = 1; i < n; ++i)
			ans = max( ans, precalculo_hori[ 1 ][ i ] + precalculo_hori[ i+1 ][ n ] );

		for (int i = 1; i < m; ++i)
			ans = max( ans, precalculo_vert[ 1 ][ i ] + precalculo_vert[ i+1 ][ m ] );
		
		return ans;
	}
	
	int ans = -2000000;
	for (int i = 1; i < n; ++i)
		for (int j = 1; j < m ; ++j)
		{
			ans = max(ans, precalculo_hori[ 1 ][ i ] + hori4[ i+1 ][ j ] + hori3[ i+1 ][ j+1 ]);
			ans = max(ans, precalculo_hori[ i+1 ][ n ] + hori1[ i ][ j ] + hori2[ i ][ j+1 ]);
		}

	for (int i = 1; i < m; ++i)
		for (int j = 1; j < n ; ++j)
		{
			ans = max(ans, precalculo_vert[ 1 ][ i ] + hori2[ j ][ i+1 ] + hori3[ j+1 ][ i+1 ]);
			ans = max(ans, precalculo_vert[ i+1 ][ m ] + hori1[ j ][ i ] + hori4[ j+1 ][ i ]);
		}

	for (int i = 1; i < n-1; ++i)
		for (int j = i+1; j < n; ++j)
			ans = max( ans, precalculo_hori[ 1 ][ i ] + precalculo_hori[ i+1 ][ j ] + precalculo_hori[ j+1 ][ n ]);

	for (int i = 1; i < m-1; ++i)
		for (int j = i+1; j < m; ++j)
			ans = max( ans, precalculo_vert[ 1 ][ i ] + precalculo_vert[ i+1 ][ j ] + precalculo_vert[ j+1 ][ m ]);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	int n, m, k, ans1, ans2;

	//////////////////////// LLENAR DATOS /////////////////////////////7
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i)
		mat[ i ][ 0 ] = mau[ i ][ 0 ] = 0;
	for (int i = 0; i < m; ++i)
		mat[ 0 ][ i ] = mau[ 0 ][ i ] = 0;

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m ; ++j)
			cin >> mat[ i ][ j ];

	/////////////////// PRECALCULO HORIZONTALES/VERTICALES /////////////7
	
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			mau[ i ][ j ] = mat[ j ][ i ];

	precalcular( m, n, precalculo_vert );

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			mau[ i ][ j ] = mat[ i ][ j ];

	precalcular( n, m, precalculo_hori );

	/////////////////// PRECALCULO HORIZONTALES //////////////////////////

	precalcular_horis( n, m );
	
	cout << EvenMoreFun(n,m,k) << endl;
	return 0;
}