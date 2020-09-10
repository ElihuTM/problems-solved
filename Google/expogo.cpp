#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <ll, ll> pii;
typedef pair <pii, ll> ppi;

map< ppi, bool> memo;
map< char, char> rev;
bool revx, revy;
string cad;

bool dp( ll x, ll y, ll pos )
{
	if ( x == 0 && y == 0)
	{
		for (int i = 0; i < cad.size(); ++i)
		{
			if ( cad[ i ] == 'N' || cad[ i ] == 'S' )
			{
				if ( revy )
					cout << rev[ cad[ i ] ];
				else
					cout << cad[ i ];
			}
			else
			{
				if ( revx )
					cout << rev[ cad[ i ] ];
				else
					cout << cad[ i ];
			}
		}
		cout << '\n';
		return true;
	}

	ppi coord( pii(x,y), pos );
	if ( memo.find( coord ) != memo.end() ) 
		return memo[ coord ];

	if ( (x&(1<<pos)) && (y&(1<<pos)) )
		return false;

	if ( !(x&(1<<pos)) && !(y&(1<<pos)) )
		return false;

	bool ans = 0;
	if ( x&(1<<pos) )
	{
		cad.push_back('E');
		ans |= dp( x-(1<<pos), y, pos+1 );
		cad.pop_back();

		if ( ans )
			return ans;

		cad.push_back('W');
		ans |= dp( x+(1<<pos), y, pos+1 );
		cad.pop_back();
	}
	else
	{
		cad.push_back('N');
		ans |= dp( x, y-(1<<pos), pos+1 );
		cad.pop_back();

		if ( ans )
			return ans;
		
		cad.push_back('S');
		ans |= dp( x, y+(1<<pos), pos+1 );
		cad.pop_back();
	}

	memo[ coord ] = ans;
	return ans;
}

int main()
{
	ll t, x, y;

	rev[ 'S' ] = 'N';
	rev[ 'N' ] = 'S';
	rev[ 'E' ] = 'W';
	rev[ 'W' ] = 'E';

	cin >> t;
	for( int c = 1; c <= t; c++ )
	{
		memo.clear();
		cin >> x >> y;

		revx = ( x < 0 );
		revy = ( y < 0 );

		cout << "Case #" << c << ": ";
		if( !dp( abs(x), abs(y), 0 ) )
			cout << "IMPOSSIBLE\n";
	}
	return 0;
}