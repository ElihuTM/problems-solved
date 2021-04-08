#include <bits/stdc++.h>

using namespace std;

int main()
{
	bitset< 30 >pos;
	char cad[ 105 ];
	int i = 0;
	
	pos.set();
	pos[ 'a' - 'a' ] = 0;
	pos[ 'e' - 'a' ] = 0;
	pos[ 'i' - 'a' ] = 0;
	pos[ 'o' - 'a' ] = 0;
	pos[ 'u' - 'a' ] = 0;
	pos[ 'y' - 'a' ] = 0;

	scanf( "%s", cad );	
	while( cad[ i ] )
	{
		if( pos[ tolower( cad[ i ] ) - 'a' ] )
			printf(".%c", tolower( cad[ i ] ) );
		++i;
	}
	printf("\n");
	
	return 0;
}
