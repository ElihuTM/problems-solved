import java.util.*;
import java.math.*;

class prob20
{
	public static void main( String Args[] )
	{
		Scanner sc = new Scanner( System.in );
		BigInteger fact[ ] = new BigInteger[ 1001 ];
		
		fact[ 0 ] = BigInteger.ONE;
		for( int i = 1; i < 1001; ++i )
			fact[ i ] = fact[ i-1 ].multiply( BigInteger.valueOf( i ) );

		int t = sc.nextInt();
		while( t-- > 0 )
		{
			int x = sc.nextInt();
			String cad = fact[ x ].toString();
			
			int sum = 0;
			for( int i = 0; i < cad.length(); ++i )
				sum += cad.charAt( i ) - '0';

			System.out.println( sum );
		}
	}
}
