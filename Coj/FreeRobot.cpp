#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

bool grid[ 17 ][ 17 ];
int n;

int movex[ ] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int movey[ ] = { 1, 1, 0, -1, -1, -1, 0, 1 };

inline bool is_pos( int x, int y )
{
	if ( x < 0 || x >= n )
		return false;

	if ( y < 0 || y >= n )
		return false;

	return true;
}

ll dfs( int x, int y, int steps )
{
	if ( steps == 0 )
		return 1;

	ll cont = 0;
	int _x, _y;

	for (int i = 0; i < 8; ++i)
	{
		_x = x + movex[ i ];
		_y = y + movey[ i ];

		if( is_pos( _x , _y ) && !grid[ _x ][ _y] )
		{
			grid[ _x ][ _y ] = true;
			cont += dfs( _x, _y , steps-1 );
			grid[ _x ][ _y ] = false;
		}
	}
	return cont;

}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
	
	ll arr[] = { 3 , 15 , 75 , 391 , 2065 , 11091 , 60215 , 330003 , 1820869 , 10103153 , 56313047 , 315071801 , 1768489771 , 9953853677 };

	int t, n;
	cin >> t;

	while( t-- )
	{
		cin >> n;
		cout << arr[ n-1 ] << endl;
	}
	/*
	cout << "ll arr[] = { ";
	for (int i = 1; i <= 14; ++i)
	{
		memset( grid, 0 , sizeof grid);
		n = i+1;

		grid[ 0 ][ 0 ] = true;
		cout << dfs( 0, 0, i );

		if ( i < 14 )
			cout << " , \n";
	}
	cout << " };\n" ;*/
	return 0;
}