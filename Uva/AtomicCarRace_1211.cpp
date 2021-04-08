#include <bits/stdc++.h>
#define maxn 10005

using namespace std;
typedef long double ld;
typedef vector <int> vi;

vi arr;
vector < vector < ld > >memo;
int r, n;
ld v, e, f, b;

ld dp( int pos, int km )
{
	if( memo[ pos ][ km ] >= 0 )
		return memo[ pos ][ km ];
	
	ld aux = 0.0;
	int dif = arr[ pos ] - arr[ pos-1 ];
	for( int i = 0; i < dif; ++i )
	{
		if( km+i >= r )
			aux += 1.0/(v-e*(ld)((km+i)-r));
		else
			aux += 1.0/(v-f*(ld)(r-(km+i)));
	}
	
	if( pos == n )
		return aux;

	ld ans1 = b + dp( pos+1, 0 );
	ld ans2 = dp( pos+1, arr[ pos ] - arr[ pos-1] + km );
	ld ans = ans1 > ans2 ? ans2 : ans1;

	return memo[ pos ][ km ] = aux + ans;
}

int main()
{
	cin >> n;
	while( n )
	{
		memo.resize( n+1 );
		arr.resize( n+1 );

		arr[ 0 ] = 0;
		for( int i = 1; i <= n; ++i )
		{
			memo[ i ].resize( maxn );
			for( int j = 0; j < maxn; ++j )
				memo[ i ][ j ] = -1;

			cin >> arr[ i ];
		}
		cin >> b;
		cin >> r >> v >> e >> f;
		
		printf("%.4llf\n", dp( 1, 0 ) );
		cin >> n;
	}
	return 0;
}
