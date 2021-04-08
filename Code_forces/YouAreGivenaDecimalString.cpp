#include <bits/stdc++.h>
#define inf 99999999

using namespace std;
typedef long long ll;

ll memo[ 10 ][ 10 ];
bool visit[ 10 ][ 10 ];
int x, y;

int dp( int pos, int next )
{	
	if( visit[ pos ][ next ] )
		return inf;
	
	if( pos == next )
		return 0;

	visit[ pos ][ next ] = 1;
	
	if( ~memo[ pos ][ next ] )
		return memo[ pos ][ next ];
	
	ll ans1 = dp( (pos+x)%10, next );
	ll ans2 = dp( (pos+y)%10, next );

	visit[ pos ][ next ] = 0;	
	return memo[ pos ][ next ] = 1 + min( ans1, ans2 );
}

int main()
{

	string cad;
	cin >> cad;
	
	//for( int i = 0; i < 10; ++i)
	//	for( int j =0; j < 10; ++j)
	//		cout << i << j;
	//cout << endl;
	
	int len = cad.size();
	for( int i = 0; i < 10; ++i )
	{
		for( int j = 0; j < 10; ++j )
		{	
			ll ans = 0;
			memset( memo, -1, sizeof memo );
			
			x = i; y = j;
			for( int k = 1; k < len; ++k ){
				memset( visit, 0, sizeof visit );
				ans += dp( cad[ k-1 ] - '0', cad[ k ] - '0' ) - 1;
			}

			if( ans >= inf)
				cout << -1;
			else
				cout << ans;
			if( j < 9 )
				cout << " ";
		}
		cout << '\n';
	}
	return 0;
}
