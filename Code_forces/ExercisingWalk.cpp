#include <iostream>

using namespace std;
typedef long long ll;

ll a,b,c,d,x,y,x1,x2,y1,y2,mv;

bool is_possible()
{
	if ( x1 == x2 )
		if ( a != 0 || b != 0)
			return false;
	
	if ( y1 == y2 )
		if ( c != 0 || d != 0 )
			return false;
		
	mv = min( a, b );
	a -= mv;
	b -= mv;

	mv = min( c, d );
	c -= mv;
	d -= mv;

	mv = ( x-a > x1 ? a : x-x1);
	x -= mv;
	a -= mv;

	mv = ( y-c > y1 ? c : x-y1);
	y -= mv;
	c -= mv;

	ll distx = x2 - x1;
	ll disty = y2 - y1;

	if ( b > distx + a - (x-x1) )
		return false;

	if ( d > disty + c - (y-y1) )
		return false;

	mv = ( x+b < x2 ? b : x2-x );
	x += mv;
	b -= mv;

	mv = ( y+d < y2 ? d : y2-y);
	y += mv;
	d -= mv;

	if ( a > distx + b - (x2-x) )
		return false;

	if ( c > disty + d - (y2-y) )
		return false;

	return true;
}
int main()
{
	int t;
	cin >> t;
	while( t-- )
	{
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		
		if ( is_possible() )
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}