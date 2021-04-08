#include <cstdio>
#include <cstring>
#define maxn 100007

using namespace std;

int arr[] = {6,5,3,1};
int memo[ maxn ];

inline int min( int a, int b)
{
	return a < b ? a : b;
}

int Dp( int n )
{
	if ( n < 0 )
		return 1000000;

	if( ~memo[ n ] )
		return memo[ n ];

	int ans = 1000000;
	for(int i = 0; i < 4; i++)
		ans = min( ans, Dp( n-arr[ i ] ));
	
	return memo[ n ] = ans + 1;
}

int main()
{
	memset(memo, -1, sizeof memo);
	memo[ 0 ] = 0;
	int n,a;

	scanf("%d",&n);
	for( int i=1; i<=n; i++)
	{
		scanf("%d",&a);
		printf("Case %d: %d\n",i,Dp( a ) );
	}
	return 0;
}