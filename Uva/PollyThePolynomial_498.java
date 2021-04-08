import java.util.*;

class PollyThePolynomial_498
{
	static long f_p( long x, int exp )
	{
		long ans = 1;

		while( exp != 0 )
		{
			if( exp%2 == 1 )
				ans *= x;

			x *= x;
			exp /= 2;
		}
		return ans;
	}

	public static void main( String args[] )
	{
		Scanner sc = new Scanner( System.in );

		while( sc.hasNext() )
		{
			String[ ] cons = sc.nextLine().split(" ");
			String[ ] xs = sc.nextLine().split(" ");
			long c[ ] = new long[ cons.length ];
			long ans, x, vari;

			for( int i = 0; i < cons.length; ++i )
				c[ i ] = Long.parseLong( cons[ i ] );

			for( int i = 0; i < xs.length; ++i )
			{
				ans = 0;
				vari = Long.parseLong( xs[ i ] );
				x = f_p( vari, cons.length-1);
				
				if( vari == 0 )
					ans = c[ cons.length-1 ];
				else
				{
					for( int j = 0; j < cons.length; ++j )
					{
						ans += x*c[ j ];
						x /= vari;
					}
				}

				System.out.print( ans );

				if( i < xs.length-1 )
					System.out.print(" ");
			}
			System.out.println();
		}
	}
}
