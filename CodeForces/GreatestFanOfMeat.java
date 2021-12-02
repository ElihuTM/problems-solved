import java.util.*;
import java.math.*;

class GreatestFanOfMeat {
	static ArrayList < Pair > answer;
	static BigInteger two = new BigInteger("2");
	static BigInteger one = BigInteger.ONE;
	static BigInteger zero = BigInteger.ZERO;

	static BigInteger get_gauss( BigInteger n ) {
		return n.multiply( n.add( one ) ).divide( two );
	}

	static BigInteger lower_bound( BigInteger i, BigInteger j, BigInteger value ) {
		BigInteger m;
		BigInteger gauss;

		while( j.subtract( i ).compareTo( BigInteger.ONE ) == 1 )
		{
			m = i.add( j.subtract( i ).divide( two ) );
			gauss = get_gauss( m );

			if( gauss.compareTo( value ) == 1 )
				j = m;
			else
				i = m;
		}

		return j;
	}

	static void get_numbers( BigInteger a, BigInteger b ) {
		BigInteger ini = new BigInteger("0");
		BigInteger fin = new BigInteger("100000000000" );
		BigInteger inicio = lower_bound( ini, fin, a );
		BigInteger gauss = get_gauss( inicio );

		System.out.println( "Inicia en " + inicio );
		while( gauss.subtract( a ).compareTo( inicio ) != 1 )
		{
			BigInteger diff = inicio.mod( b );
			if( diff.equals( zero ) ) {
				answer.add( new Pair( inicio, gauss.subtract( a ) ) );
				inicio = inicio.add( b );
			}
			else {
				inicio = inicio.add( b.subtract( diff ) );
			}

			gauss = get_gauss( inicio );
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );

		int t = sc.nextInt();
		while( t-- > 0 ) {
			answer = new ArrayList < Pair >();
			long dividendo = sc.nextLong();
			long divisor = sc.nextLong();

			BigInteger a = BigInteger.valueOf( dividendo );
			BigInteger b = BigInteger.valueOf( divisor );

			get_numbers( a, b );
			System.out.println( answer.size() );
			for ( Pair ans : answer ) {
				System.out.println( ans.getKey() + " " + ans.getValue() );
			}
		}
	}
}

class Pair {
	private BigInteger key;
	private BigInteger value;

	public Pair( BigInteger key, BigInteger value ) {
		this.key = key;
		this.value = value;
	}

	public BigInteger getKey() {
		return key;
	}

	public BigInteger getValue() {
		return value;
	}
}