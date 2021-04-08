#include <bits/stdc++.h>
#define maxn 101

using namespace std;

struct part
{
	int eq, cont, time;
	bool participo;

	void clear( int i )
	{
		participo = false;
		eq = i;
		cont = 0;
		time = 0;
	}

	void add( int tim )
	{
		++cont;
		time += tim;
	}

	bool operator < ( const part &p )const
	{
		return cont > p.cont || (cont == p.cont && time < p.time) || (cont == p.cont && time == p.time && eq < p.eq );
	}
};

int arr[ maxn ][ 10 ];
part participante[ maxn ];

void pedir( int &eq, int &pro, int &tim, char &vere, string cad )
{
	stringstream ss;

	ss << cad;
	ss >> eq >> pro >> tim >> vere;
}

int main()
{
	int caso, equipo, problema, tiempo;
	char veredicto;
	bool ban = false;
	string cad;

	cin >> caso;
	getline( cin, cad);
	getline( cin, cad);
	
	while( caso-- )
	{
//		cout << "-- caso " << caso+1 << endl;
		memset( arr, 0, sizeof arr );
		for( int i = 0; i < maxn; ++i )
			participante[ i ].clear( i );

		getline( cin, cad );
		while( cad != "" )
		{
			pedir( equipo, problema, tiempo, veredicto, cad );
			
//			cout << equipo << " " << problema << " " << tiempo << " " << veredicto << '\n';
			participante[ equipo ].participo = true;
			if( veredicto == 'I' && arr[ equipo ][ problema ] != -1)
				arr[ equipo ][ problema ] += 20;
			else if( veredicto == 'C' && arr[ equipo ][ problema ] != -1 )
			{
				participante[ equipo ].add(tiempo + arr[ equipo ][ problema ] );
				arr[ equipo ][ problema ] = -1;
			}
			getline( cin, cad );
		}
		
		sort( participante, participante+maxn );
		for( int i = 0; i < maxn; ++i )
			if( participante[ i ].participo )
				cout << participante[ i ].eq << " " << participante[ i ].cont << " " << participante[ i ].time << '\n';
	
		if( caso )
			cout << '\n';
	}
	return 0;
}
