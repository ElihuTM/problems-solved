#include <bits/stdc++.h>
#define ep 1e-7
#define maxn 10000

using namespace std;
typedef long double ld;

int p, q, r, s, t, u;
//const ld PI = acos(-1);

ld eq( ld x ){	return p*exp(-x) + q*sin( x ) + r*cos( x ) + s*tan( x ) + t*x*x + u; }
int it;

ld binary( ld left, ld right )
{
	++it;
	ld m = left + ( right - left ) / 2;
	ld ev = eq( m );
	
	if( fabs( ev ) <= ep )
		return m;
	
	if( it == maxn )
		return m;

	if( ev * eq( left ) < 0 )
		return binary( left, m );
	else
		return binary( m, right);
}

int main()
{
	while( scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) != EOF )
	{
		it = 0;
		if( eq( 0 ) * eq( 1 ) > 0 )
			printf("No solution\n");
		else
			printf("%.4llf\n", binary( 0, 1 ) );
	}

	return 0;
}
