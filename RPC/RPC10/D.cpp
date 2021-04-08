#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int diagonal( int x, int y )
{
	if( y <= 0 && 2*y <= x && x <= -2*y )
		return 0;
	else if( x <= 0 )
		return -1;
	return 1;
}

int trian( int diag, int x, int y )
{
	if( diag == -1 ) return ( x == 0 ? y : -x );
	if( diag == 0 ) return 0-y+1;
	return x ;
}

ll sum( ll n )
{
	if( n == 0 )
		return 0;
	return 4*n*n - 1;
}

ll parcial( int trian, int diag, int x, int y )
{
	if( x == 2*trian-1 && y == 1-trian )
		return 8*trian - 4;

	
}

int main()
{
	int t, diag, trian;
	ll ans;
	cin >> t;

	while( t-- )
	{
		cin >> x >> y;

		///// calcular que tipo de diagonal es
		diag = diagonal( x, y );

		//// calcular en que triangulo se encuentra
		trian = triangulos( diag, x, y );

		/// sumarle a la respuesta la suma de los triangulos anteriores
		ans = sum( trian-1 );

		/// sumarle el parcial
		ans += parcial( trian, diag, x, y );
	}
	return 0;
}
