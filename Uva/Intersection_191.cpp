#include <bits/stdc++.h>

using namespace std;

struct Point
{
	int x, y;

	Point() { x == y == 0; }
	Point( int a, int b ) : x( a ), y( b ) { }
	
	Point operator + ( const Point &pepe ) const {
		return Point( x + pepe.x, y + pepe.y );
	}
	Point operator - ( const Point &pepe ) const {
		return Point( x - pepe.x, y - pepe.y );
	}
	int operator ^ ( const Point &pepe ) const {
		return x*pepe.y - y*pepe.x;
	}
};

int cross( Point a, Point b, Point c ) {
	return ( b-a ) ^ ( c-a );
}

int ccw( Point a, Point b, Point c )
{	
	if( cross( a, b, c ) == 0 )
		return 0;

	return cross( a, b, c ) > 0 ? 1 : -1;
}

bool onSegment ( Point a, Point b, Point c )
{
	if( min( b.x, c.x) <= a.x && a.x <= max(b.x, c.x) &&  min( b.y, c.y) <= a.y && a.y <= max(b.y, c.y) )
		return true;

	return false;
}

bool intersection( Point a, Point b, Point c, Point d )
{
	int x1 = ccw( a, b, c );
	int x2 = ccw( a, b, d );
	int x3 = ccw( c, d, a );
	int x4 = ccw( c, d, b );
	
	if( x1 != x2 && x3 != x4 )
		return true;

	if( x1 == 0 && onSegment( c, a, b ) )
		return true;

	if( x2 == 0 && onSegment( d, a, b ) )
		return true;
	
	if( x3 == 0 && onSegment( a, c, d ) )
		return true;

	if( x4 == 0 && onSegment( b, c, d ) )
		return true;
	
	return false;
}

bool inter( int x1, int y1, int x2, int y2, Point a, Point b )
{
	if( min( x1, x2 ) <= a.x && a.x <= max( x1,x2 ) && min( y1, y2 ) <= a.y && a.y <= max( y1,y2) )
		return true;
	
	if( min( x1, x2 ) <= b.x && b.x <= max( x1,x2 ) && min( y1, y2 ) <= b.y && b.y <= max( y1,y2) )
		return true;
	
	if( intersection( Point(x1,y1),Point(x2,y1), a, b ) )
		return true;
	
	if( intersection( Point(x2,y2),Point(x2,y1), a, b ) )
		return true;
	
	if( intersection( Point(x2,y2),Point(x1,y2), a, b ) )
		return true;
	
	if( intersection( Point(x1,y1),Point(x1,y2), a, b ) )
		return true;
	
	return false;
}

int main()
{
	int t, p1x, p1y, p2x, p2y, x1, x2, y1, y2;
	cin >> t;

	while( t-- )
	{
		cin >> p1x >> p1y >> p2x >> p2y  >> x1 >> y1 >> x2 >> y2;

		if( inter( x1, y1, x2, y2, Point(p1x,p1y), Point(p2x,p2y) ) )
			cout << "T\n";
		else
			cout << "F\n";
	}
	return 0;
}
