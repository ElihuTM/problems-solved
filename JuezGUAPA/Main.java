import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner( System.in );

		BigInteger memo[ ] = new BigInteger[ 10004 ];
		memo[ 0 ] = BigInteger.ONE;
		memo[ 1 ] = BigInteger.ONE;

		for ( int i = 2; i<10004 ; ++i) {
			memo[ i ] = memo[ i-1 ].add( memo[ i-2 ] );
		}

		int t = sc.nextInt();
		for( int casos = 0; casos < t; ++casos ){
			int n = sc.nextInt();

			System.out.println( memo[ n ] );
		}
	}
}