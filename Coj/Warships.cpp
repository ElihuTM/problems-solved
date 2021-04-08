#include <iostream>
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	string tobby, otro;
	int s1, s2;

	while( cin >> tobby >> s1 )
	{
		cin >> otro >> s2;

		if ( tobby[ 0 ] == otro[ 0 ] )
		{
			if( s1 == s2 )
				cout << "Draw\n";
			else if( s1 > s2 )
				cout << "Tobby\n";
			else
				cout << "Naebbirac\n";
		}
		else if ( tobby[ 0 ] == 'B' )
		{
			if ( otro[ 0 ] == 'C' )
			{
				if ( 2*s2 > s1)
					cout << "Naebbirac\n";
				else
					cout << "Tobby\n";
			}
			else
			{
				if( 2*s1 > s2)
					cout << "Tobby\n";
				else
					cout << "Naebbirac\n";
			}
		}
		else if( tobby[ 0 ] == 'C')
		{
			if ( otro[ 0 ] == 'D' )
			{
				if ( 2*s2 > s1)
					cout << "Naebbirac\n";
				else
					cout << "Tobby\n";
			}
			else
			{
				if( 2*s1 > s2)
					cout << "Tobby\n";
				else
					cout << "Naebbirac\n";
			}
		}
		else
		{
			if ( otro[ 0 ] == 'B' )
			{
				if ( 2*s2 > s1)
					cout << "Naebbirac\n";
				else
					cout << "Tobby\n";
			}
			else
			{
				if( 2*s1 > s2)
					cout << "Tobby\n";
				else
					cout << "Naebbirac\n";
			}
		}
	}
	return 0;
}