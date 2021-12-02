#include <iostream>
#include <cstring>
#define maxn 1003

using namespace std;

bool calculated[ maxn ][ maxn ];
ll number_of_digits, module;
string cad, answer;

bool dp ( int residue, int position )
{
	if( position == number_of_digits ) {
		
		if( residue % module == 0 ) {
			cout << answer << '\n';
			return true;
		}

		return false;
	}
	
	if( calculated[ residue ][ position ] )
		return false;
	
	ll current_residue;
	calculated[ residue ][ position ] = true;
	
	if( cad[ position ] != '?' ) {
		current_residue = (residue * 10 + cad[ position ] -'0') % module;
		return dp( current_residue, position + 1 );
	}
	else {
		
		for( int new_digit = 0; new_digit < 10; ++new_digit)
		{
			answer[ position ] = '0' + new_digit;
			current_residue = ( residue * 10 + new_digit ) % module;
			if( dp( current_residue, position + 1 ) )
				return true;
		}
		return false;
	}
}

bool was_solve (  )
{
	if( cad[ 0 ] != '?' )
		return dp( cad[ 0 ] - '0', 1  );

	for( int first_digit = 1; first_digit <= 9; ++first_digit )
	{
		answer[ 0 ] = '0' + first_digit;
		if( dp( first_digit, 1 ) )
			return true;
	}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> cad >> module;
	
	//initialization of variables
	answer = cad; number_of_digits = cad.size();
	memset( calculated, false, sizeof( calculated ) );

	if( not was_solve( ) )
		cout << "*\n";

	return 0;
}
