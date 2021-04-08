#include <bits/stdc++.h>
#define maxn 100007

using namespace std;

int padre[ maxn ];
int tam[ maxn ];

int padrote( int nodo ){
	return nodo == padre[ nodo ] ? nodo : padre[ nodo ] = padrote( padre[nodo] );
}

bool unionFind(int a, int b)
{
	int c = padrote( a );
	int d = padrote( b );

	if ( c == d)
		return false;

	if ( tam[ c ] > tam[ d ])
	{
		tam[ c ] += tam[ d ];
		padre[ d ] = c;
	}
	else
	{
		tam[ d ] += tam[ c ];
		padre[ c ] = d;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	map<string, int> hashTable;
	string friend1, friend2;
	int n,query,cont,a,b;

	cin >> n;
	while(n--)
	{
		cont = 0;
		for (int i = 0; i < maxn; ++i)
		{
			padre[ i ] = i;
			tam[ i ] = 1;
		}

		cin >> query;
		for (int i = 0; i < query; ++i)
		{
			cin >> friend1 >> friend2;
			if ( hashTable.find( friend1 ) == hashTable.end() )
				a = hashTable[ friend1 ] = ++cont;
			else
				a = hashTable[ friend1 ];

			if ( hashTable.find( friend2 ) == hashTable.end() )
				b = hashTable[ friend2 ] = ++cont;
			else
				b = hashTable[ friend2 ];

			unionFind( a, b);
			cout << tam[ padrote( a )] << "\n";
		}

		if ( n )
			hashTable.clear();
	}
	return 0;
}