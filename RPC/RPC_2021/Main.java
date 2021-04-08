import java.util.*;
import java.math.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );
		String cad = sc.next();

		BigInteger num[] = new BigInteger[ 10 ];
		BigInteger dos = new BigInteger( "2" );
		BigInteger tres = new BigInteger( "3" );
		BigInteger cuatro = new BigInteger( "4" );

		for( int i = 0; i < 10; ++i ) {
			num[ i ] = new BigInteger( cad );
			num[ i ] = num[ i ].add( BigInteger.valueOf( i ) );
		}

		for ( int i = 0; i < 9; ++i )
		{
			BigInteger aux = num[ i ].multiply( num[ i+1 ] );
			aux = aux.multiply( tres ).divide( dos );
			aux = aux.subtract( num[ i ] ).mod( cuatro );

			if ( aux.equals( BigInteger.ZERO ) )
			{
				System.out.println( num[ i ].toString() );
				break;
			}
		}
	}
} 