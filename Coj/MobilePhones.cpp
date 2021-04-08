#include <iostream>
#include <cstring>
#define maxn 1030
#define endl '\n'

using namespace std;

int ft[ maxn ][ maxn ];
int n;

inline int LSOne( int k )
{
	return k&(-k);
}

inline int adjust( int i, int j, int value )
{
	for ( int a = i ; a <= n; a += LSOne( a ) )
		for( int b = j ; b <= n; b += LSOne( b ) )
			ft[ a ][ b ] += value;
}

inline int query( int i, int j )
{
	int total = 0;
	for ( int a = i; a; a -= LSOne( a ) )
		for ( int b = j; b ; b -=LSOne( b ) )
			total += ft[ a ][ b ];
	return total;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	memset( ft, 0, sizeof ft );
	int op, w, x, y, z, tot;

	cin >> op >> n;
	cin >> op;
	while( op != 3 )
	{
		if ( op == 1 )
		{
			cin >> x >> y >> w;
			adjust( x+1, y+1 , w );
		}
		else
		{
			cin >> x >> y >> w >> z;
			
			tot = query( w+1, z+1 );
			tot -= query( w+1, y );
			tot -= query( x, z+1 );
			tot += query( x, y );

			cout << tot << endl;
		}
		cin >> op;
	}
	return 0;
}