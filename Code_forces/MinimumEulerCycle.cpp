#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vi;

map<ll, ll> posicion;
vi next_vertex;
ll n;

ll calc( ll pos )
{
	if( pos == 1 )
		return 2*(n-1);

	return 2*(n-posicion[ pos ])-1;
}

void print( ll &pos, ll &l, ll &r )
{
	if ( pos == 1 )
	{
		
	}


}

int main()
{
	ll t, l, r, ini, fin, pos;

	cin >> t;
	while( t-- )
	{
		cin >> n >> l >> r;
		
		posicion.clear();
		next_vertex.clear();
		ini = 1, fin = n, pos = 0;

		while( ini < fin )
		{
			next_vertex.push_back( ini );
			next_vertex.push_back( fin );
			nex[ ini ] = (++pos);
			nex[ fin ] = (++pos);

			--ini;
			--fin;
		}

		if ( ini == fin )
		{
			nex[ ini ] = (++pos);
			next_vertex.push_back( ini );
		}

		ll sum = 0, cur = calc( 1 ); pos = 0;

		while( sum + cur < l )
		{
			sum += cur;
			cur = calc( next_vertex[ ++pos ] );
		}

		l -= sum;
		r -= sum;

		while( l < r )
			print( pos++, l, r );
	}
	return 0;
}	
	