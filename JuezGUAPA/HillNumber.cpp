#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll memo[ 20 ][ 10 ][ 2 ][ 2 ];
string cad;

ll dp( int pos, int ant, bool sub, bool tope )
{
	if ( pos == cad.size() )
		return 1;

	if ( ~memo[ pos ][ ant ][ sub ][ tope ] )
	{
		//cout << "prev de  " << pos << ' ' << ant << ' ' << sub << ' ' << tope << " = " << memo[ pos ][ ant ][ sub ][ tope ] << '\n';
		return memo[ pos ][ ant ][ sub ][ tope ];
	}

	ll ans = 0, lim;
	if ( sub )
	{
		if ( tope )
			for (int i = ant+1; i <= cad[ pos ]-'0' ; ++i)
				ans += dp( pos+1, i, 1, i == cad[ pos ]-'0' );
		else
			for (int i = ant+1; i <= 9 ; ++i)
				ans += dp( pos+1, i, 1, false );
	}
	
	if ( !tope )
		ans += dp( pos+1, ant, sub, tope );
	else
	{
		if ( ant <= cad[ pos ]-'0' )
			ans += dp( pos+1, ant, sub, ant == cad[ pos ]-'0');
	}

	if ( tope )
	{
		for (int i = 0; i < ant; ++i)
		{
			if ( i > cad[pos]-'0')
				break;
			ans += dp( pos+1, i, 0, i == cad[ pos ]-'0' );
		}
	}
	else
	{
		for (int i = 0; i < ant; ++i)
			ans += dp( pos+1, i, 0, 0 );
	}

	//cout << "ans de  " << pos << ' ' << ant << ' ' << sub << ' ' << tope << " = " << ans << '\n';
	return memo[ pos ][ ant ][ sub ][ tope ] = ans;
}

bool is_Hill_number( string &n )
{
	bool crece = true;
	for (int i = 0; i < n.size()-1; ++i)
	{
		if( crece && n[ i+1 ] < n[ i ] )
			crece = false;
		else if( !crece && n[ i+1 ] > n[ i ] )
			return false;
	}

	return true;
}

int main()
{
	memset( memo, -1, sizeof memo );
	cin >> cad;

	if ( is_Hill_number( cad ) )
	{
		ll ans = 0;
		for (int i = 0; i <= cad[ 0 ]-'0' ; ++i)
			ans += dp( 1, i, 1, i == cad[ 0 ]-'0' );
		cout << ans-1 << '\n';
	}
	else
		cout << "-1\n";
		
	return 0;
}	