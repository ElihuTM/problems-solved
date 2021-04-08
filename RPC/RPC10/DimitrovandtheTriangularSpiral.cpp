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

int triangulos( int diag, int x, int y )
{
	if( diag == -1 ) return y-x;
	if( diag == 0 ) return 0-y+1;
	return x+y ;
}

ll sum( ll n )
{
	if( n == 0 )
		return 0;
	return 4*n*n;
}

ll parcial( int trian, int diag, int x, int y )
{
	int x1 = 0, y1 = trian;
	int x3 = 2*trian-1, y3 = 1-trian;
	int x2 = -x3, y2 = y3;

	if( x == x3 && y == y3 )
		return 8*trian - 4;
	
	if( diag == 1)
		return x + 3*x3;
	if( diag == -1 )
		return x-x2 + 2*x3;

	return x3-x;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int t, diag, trian, x, y;
	ll ans;
	cin >> t;

	while( t-- )
	{
		cin >> x >> y;
		//cout << x << " " << y << endl;

		///// calcular que tipo de diagonal es
		diag = diagonal( x, y );
		//cout << "Diagonal :" << diag << endl;

		//// calcular en que triangulo se encuentra
		trian = triangulos( diag, x, y );
		
		//cout << "Triangulo No. " << trian << endl;

		/// sumarle a la respuesta la suma de los triangulos anteriores
		ans = sum( trian-1 );
		
		//cout << "Suma de los anteriores: " << ans << endl;
		/// sumarle el parcial
		ans += parcial( trian, diag, x, y );
		//cout << "Paricla: " << parcial( trian, diag, x, y ) << endl;

		cout << ans << '\n';
	}
	return 0;
}
