import java.util.*;
import java.math.*;

class prob16
{
	public static int f_p( int exp )
	{
		BigInteger x = new BigInteger( "2" );
		BigInteger ans = BigInteger.ONE;

		while( exp > 0 )
		{
			if( exp%2 == 1 )
				ans = ans.multiply( x );

			x = x.multiply( x );
			exp /= 2;
		}
		
		int ansi = 0;
		String cad = ans.toString();
		for( int i = 0; i < cad.length(); ++i )
			ansi += cad.charAt( i ) - '0';

		return ansi;
	}

	public static void main( String Args[] )
	{
		Scanner sc = new Scanner( System.in );

		int t = sc.nextInt();
		while( t-- > 0 )
		{
			int n = sc.nextInt();
			System.out.println( f_p( n ) );
		}
	}
}
