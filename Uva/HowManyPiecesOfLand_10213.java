import java.util.*;
import java.math.*;

class HowManyPiecesOfLand_10213
{
	public static BigInteger moser( int x )
	{
		BigInteger n = BigInteger.valueOf( x );
		BigInteger n_1 = BigInteger.valueOf( x-1 );
		BigInteger n_2 = BigInteger.valueOf( x-2 );
		BigInteger n_3 = BigInteger.valueOf( x-3 );
		BigInteger ans1 = n.multiply( n_1 );
		BigInteger ans2 = ans1;

		ans1 = ans1.multiply( n_2.multiply( n_3) );
		ans1 = ans1.divide( BigInteger.valueOf( 24 ) );
		ans2 = ans2.divide( BigInteger.valueOf( 2 ) );

		ans1 = ans1.add( ans2 );
		return ans1.add( BigInteger.ONE );
	}

	public static void main( String args[] )
	{
		Scanner sc = new Scanner( System.in );

		int t = sc.nextInt();
		while( (t--) > 0 )
		{
			int n = sc.nextInt();
			System.out.println( moser( n ) );
		}
	}
	
}
