#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n,a;
       	cin >> n;
	while( n-- )
	{
		cin >> a;
		if( a == 1 )
			cout << 1 << endl;
		else if( a == 2 )
			cout << 2 << endl;
		else
			cout << 4 + ( 3 * ( a-3 ) ) << endl;
	}
	return 0;
}
