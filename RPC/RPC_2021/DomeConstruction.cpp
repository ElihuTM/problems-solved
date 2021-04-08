#include <bits/stdc++.h>
#define maxn 100005

using namespace std;
typedef long long ll;
typedef long double ld;

ld arr[ maxn ];

int main()
{
	int n, k;
	ld x, y, z,dist;

	scanf("%d%d",&n,&k);


	for (int i = 0; i < n; ++i)
	{
		scanf("%llf%llf%llf", &x, &y, &z);
		dist = (x*x) + (y*y) + (z*z);
		arr[ i ] = sqrt( dist );
	}

	sort( arr, arr+n );

	printf("%.8llf\n",arr[ k-1 ] );
	return 0;
}