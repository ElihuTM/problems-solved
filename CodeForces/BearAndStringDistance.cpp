#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

char cad[ maxn ];
char ans[ maxn ];

int main()
{
	int n, k;
	char salto;

	scanf("%d%d%c",&n,&k,&salto);
	scanf("%s",cad);

	for (int i = 0; i < n; ++i)
	{
		if ( k == 0 )
			ans[ i ] = cad[ i ];
		else
		{
			int ar = 'z' - cad[ i ];
			int ab = cad[ i ] - 'a';

			if ( ar > ab )
			{
				ans[ i ] =  cad[ i ] + min( ar, k );
				k -= min( ar, k );
			}
			else
			{
				ans[ i ] =  cad[ i ] - min( ab, k );
				k -= min( ab, k );
			}
		}
	}
	ans[ n ] = '\0';

	if ( k )
		printf("-1\n");
	else
		printf("%s\n",ans );
	return 0;
}