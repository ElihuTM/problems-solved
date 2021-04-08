#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t, n, k;
	scanf("%d", &t );

	while( t-- )
	{
		scanf("%d %d", &n, &k );
		printf("%lf\n", (double)(k*1000000000000000L) / ((1L<<n)-2*n-2) );
	}
	return 0;
}
