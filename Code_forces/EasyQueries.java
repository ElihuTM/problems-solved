import java.util.*;
import java.math.*;

class EasyQueries
{
	public static void main( String args[] )
	{
		Scanner sc = new Scanner( System.in );
		int n = sc.nextInt();
		int x = sc.nextInt();
		int q = sc.nextInt();
	
		SegmentTree segment = new SegmentTree( n );
		
		BigInteger y = BigInteger.valueOf( x );
		int t,a,b,c;

		while( q-- > 0 )
		{
			t = sc.nextInt();
			a = sc.nextInt();
			b = sc.nextInt();

			if( t == 1 )
			{
				c = sc.nextInt();
				segment.update( 1, 0, n-1, a-1, b-1, c );
			}
			else
				System.out.println( segment.query( 1, 0, n-1, a-1, b-1 ).multiply( y ) );
		}
	}
}

class SegmentTree
{
	private BigInteger[] arbol;
	private long[] cambios;
	
	private void propagar( int p, int i, int j )
	{
		arbol[ p ] = arbol[ p ].add( BigInteger.valueOf( (j-i+1)*cambios[ p ]) );

		if( i != j )
		{
			cambios[ p<<1 ] += cambios[ p ];
			cambios[ (p<<1)+1 ] += cambios[ p ];
		}

		cambios[ p ] = 0;
	}

	public BigInteger query( int p, int i, int j, int a, int b )
	{
		if( i > b || j < a )
			return BigInteger.ZERO;
	
		propagar( p, i, j );
		if( i >= a && j <= b )
			return arbol[ p ];

		BigInteger l = query( p<<1, i, (i+j)>>1, a, b );
		BigInteger r = query( (p<<1)+1, ((i+j)>>1)+1, j, a, b );

		return l.add( r );
	}
	
	public void update( int p, int i, int j, int a, int b, long value )
	{
		propagar( p, i ,j );

		if( i > b || j < a )
			return;

		if( i >= a && j <= b )
		{
			arbol[ p ] = arbol[ p ].add( BigInteger.valueOf( (j-i+1)*value ) );
			if( i != j )
			{
				cambios[ p<<1 ] += value;
				cambios[ (p<<1)+1 ] += value;
			}
			return;
		}

		update( p<<1, i, (i+j)>>1, a, b, value );
		update( (p<<1)+1, ((i+j)>>1)+1, j, a, b, value );

		arbol[ p ] = arbol[ p<<1 ].add( arbol[ (p<<1)+1 ] );
	}

	public SegmentTree( int n )
	{
		cambios = new long[ 6*n ];
		arbol = new BigInteger[ 6*n ];

		for( int i = 0; i < 6*n; ++i )
		{
			cambios[ i ] = 0;
			arbol[ i ] = BigInteger.ZERO;
		}
	}
}
