import java.util.*;
import java.math.*;

class NateAndIntegerCoefficient {
	public static void main(String[] args) {
		 Scanner sc = new Scanner( System.in );

		 int t = sc.nextInt();
		 while( t-- > 0 ) {
		 	BigDecimal four = new BigDecimal( "4" );
		 	BigDecimal two = new BigDecimal( "2" );
		 	BigDecimal one = new BigDecimal( "1" );
		 	MathContext mc = new MathContext(10);

		 	BigDecimal a = new BigDecimal( sc.nextLong() );
		 	BigDecimal b;
		 	long n = sc.nextLong();
		 	

		 	BigDecimal raiz = a.pow( 2 ).subtract( four ).sqrt(mc);
		 	a = a.add( raiz ).divide( two );

		 	if( n < 0 ) {
		 		b = one.divide( fast_pow(a, 2*n-n) ).add( fast_pow)
		 	}
		 	System.out.println( raiz );
		 }
	}
}