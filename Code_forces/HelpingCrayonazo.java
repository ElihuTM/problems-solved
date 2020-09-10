import java.util.*;
import java.math.*;

class HelpingCrayonazo
{
	static Set<BigInteger> factores = new HashSet<BigInteger>();
	
	static BigInteger pollard_rho( BigInteger n )
	{
		BigInteger rand1 = BigInteger.valueOf( (long)(Math.random( )*1000000) );
		BigInteger rand2 = BigInteger.valueOf( (long)(Math.random( )*1000000) );
		
		BigInteger x = rand1.mod( n ).add( BigInteger.ONE );
		BigInteger c = rand2.mod( n ).add( BigInteger.ONE );
		BigInteger two = BigInteger.valueOf( 2 );
		BigInteger d = BigInteger.ONE;
		BigInteger y = x;

		while( d.equals( BigInteger.ONE ) ) {
			x = x.multiply( x ).add( c ).mod( n );
			y = y.multiply( y ).add( c ).mod( n );
			y = y.multiply( y ).add( c ).mod( n );

			d = x.subtract( y ).abs().gcd( n );
			if( d.equals( n ) )
				return pollard_rho( n );
		}

		return d;
	}

	static void factorize( BigInteger n )
	{
		if ( n.equals( BigInteger.ONE ) ) return;

		if( n.isProbablePrime(10) )
		{
			factores.add( n );
			return;
		}

		BigInteger div = pollard_rho( n );
		factorize( div );
		factorize( n.divide( div ) );
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );

		long sqr[ ] = new long[ 1000001 ];
		for ( long i=1; i < 1000001; ++i) {
			sqr[ (int)i ] = i*i;
		}

		long n = sc.nextLong();
		boolean flag = false;

		for( long i=1; i<1000001; ++i )
		{
			long cuadrado = sqr[ (int)i ];
			factores.clear();

			if( n % cuadrado == 0 )
			{
				long numero = n / cuadrado;
				while( numero % 2 == 0 )
				{
					numero /= 2;
					factores.add( BigInteger.valueOf( 2 ) );
				}

				factorize( BigInteger.valueOf( n ) );
				if( factores.size() == 1 ) {
					flag = true;
					break;
				}
			}
		}

		if( flag )
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}