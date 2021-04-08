#include <bits/stdc++.h>

using namespace std;
typedef vector< double > vd;
typedef vector< vd > vvd;
typedef vector< int > vi;

double minCostMatching( const vvd &cost )
{
	int n = cost.size();

	//////////// DECLARAR DOS NUEVOS VECTORES DE DOUBLES DE TAMAÑO N ///////////
	
/*                                construct dual feasible solution                                 */
	
	vd u( n ); ///// ARREGLO DE MENORES POR FILA
	vd v( n ); ///// ARREGLO DE MENORES POR COLUMNA


	/////////// ENCONTRAR EL MENOR POR FILA ///////////
	for (int i = 0; i < n; ++i )
	{
		u[ i ] = cost[ i ][ 0 ]; 
		for (int j = 0; j < n; ++j )
			u[ i ] = min( u[ i ], cost[ i ][ j ] );
	}

	/////////// UNA VEZ RESTADO EL MENOR POR FILA /////
	/////////// ENCONTRAR EL MENOR POR COLUMNA ////////
	for (int j = 0; j < n; ++j)
	{
		v[ j ] = cost[ 0 ][ j ] - u[0];
		for (int i = 0; i < n; ++i)
			v[ j ] = min( v[ j ], cost[ i ][ j ] - u[ i ] );
	}


/*                 construct primal solution satisfying complementary slackness					       */

	////////// DECLARAR DOS NUEVOS VECTORES ENTEROS DE TAMAÑO N INICIALIZADOS CON -1 /////// 
	vi Lmate = vi( n, -1 );
	vi Rmate = vi( n, -1 );

	int mated = 0;
	for (int i = 0; i < n; ++i )
		for (int j = 0; j < n; ++j )
		{
			if( Rmate[ j ] != -1 ) continue;
			if( fabs( cost[ i ][ j ] - u [ i ] - v[ j ] ) < 1e-10 ) ////// SI EL VALOR ES IGUAL A 0
			{
				Lmate[ i ] = j;
				Rmate[ j ] = i;
				++mated;
				break;
			}
		}

	vd dist( n );
	vi seen( n );
	vi dad( n );

	while( mated < n )
	{
		int s = 0;

		while( Lmate[ s ] != -1 ) ++s;

		fill( dad.begin(), dad.end(), -1 );
		fill( seen.begin(), seen.end(), 0);

		for (int k = 0; k < n; ++k)
			dist[ k ] = cost[ s ][ k ] - u[ s ] - v[ k ];

		int j = 0;
		while( true )
		{
			j = -1;

			for( int k=0; k < n ; ++k)
			{
				if( seen[ k ] ) continue;
				if( j == -1 || dist[ k ] < dist[ j ] ) j = k;
			}
			seen[ j ] = 1;

			if( Rmate[ j ] == -1 ) break;

			const int i = Rmate[ j ];
			for (int k = 0; k < n; ++k)
			{
				if ( seen[ k ] ) continue;

				const double new_dist = dist[ j ] + cost[ i ][ k ] - u[ i ] - v[ k ];
				if( dist[ k ] > new_dist )
				{
					dist[ k ] = new_dist;
					dad[ k ] = j;
				}
			}
		}

		for (int k = 0; k < n; ++k)
		{
			if( k == j || !seen[ k ] ) continue;
			const int i = Rmate[ k ];
			v[ k ] += dist[ k ] - dist[ j ];
			u[ i ] -= dist[ k ] - dist[ j ];
		}
		u[ s ] += dist[ j ];

		while( dad[ j ] >= 0 )
		{
			const int d = dad[ j ];
			Rmate[ j ] = Rmate[ d ];
			Lmate[ Rmate[ j ] ] = j;
			j = d;
		}
		Rmate[ j ] = s;
		Lmate[ s ] = j;

		++mated;
	}

/////////////////////// AQUI ESTA LA RESPUESTA /////////////////////////

	
	//////////// SE RELACIONA I CON LMATE[ I ] ////////////
	double value = 0;
	for (int i = 0; i < n; ++i)
	{
		cout << i << " " << Lmate[ i ] << endl;
		value += cost[ i ][ Lmate[ i ] ];
	}

	return value;
} 


int main()
{
	vvd matriz;
	double c;
	int n;

	cin >> n;

	matriz = vvd( n );

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> c;
			matriz[ i ].push_back( c ); 
		}
	}

	cout << minCostMatching( matriz ) << endl;

	return 0;
}