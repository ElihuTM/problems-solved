#include <iostream>
#include <bitset>

using namespace std;

bitset<27> dicc;

void set_chars( string cad )
{
	for (int i = 0; i < cad.size(); ++i)
		dicc[ cad[ i ]-'A' ] = true;
}

bool is_pos( string cad )
{
	for (int i = 0; i < cad.size(); ++i)
		if ( !dicc[ cad[ i ]- 'A'] )
			return false;
	return true;
}

int main()
{
	dicc.reset();
	string cad;

	set_chars( "GENIUS" );
	set_chars( "IRENE" );
	set_chars( "REVOLVER" );
	set_chars( "WATSON" );

	cin >> cad;

	if ( is_pos( cad ) )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
