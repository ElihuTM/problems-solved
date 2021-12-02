#include <bits/stdc++.h>
#define maxn 203
#define m_p(a,b) make_pair(a,b)
#define ff first
#define ss second

using namespace std;
typedef pair <int,int> pii;

int n, m;
int jug[ 8 ];
int arr[ maxn ];

int busq( int ini, int val )
{
	for (int i = ini; i < n; ++i)
		if ( arr[ i ] == val )
			return i;

	return n;
}

int find( int ini, pii card )
{
	if( card.ff == 3 )
		for (int i = 1; i < n; ++i)
			if( arr[ i ] == card.ss )
				return i;

	int it = busq( ini, card.ss );

	if ( card.ff == 1 )
		return it;
	
	return busq( it+1, card.ss );
}

int main()
{
	memset( jug, 0, sizeof jug);

	string cad;
	map<string, int> mp;
	queue <pii> next;
	int k, dif = 0, aux, num;

	cin >> n >> k;

	for( int i = 1; i < n; ++i )
	{
		cin >> cad;
		if( mp.find(cad) == mp.end() )
			mp[ cad ] = dif++;

		arr[ i ] = mp[ cad ];
	}

	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		cin >> num >> cad;
		next.push( m_p(num,mp[ cad ]) );
	}

	int in = 0;
	while( 1 )
	{
		pii card = next.front(); next.pop(); next.push(card);
		jug[ in ] = find( jug[ in ]+1, card );

		//cout << "jugador " << in+1 << " a la " << jug[ in ] << '\n';

		if( jug[ in ] >= n )
		{
			cout << in+1 << '\n';
			return 0;
		}

		in = (in+1)%k;
	}
	return 0;
}