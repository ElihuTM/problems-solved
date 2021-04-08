#include <bits/stdc++.h>

using namespace std;

struct nodo
{
	char c;
	nodo* next = nullptr;

	nodo( char a ) : c( a ), next( nullptr ) {}
};

struct lista
{
	nodo *pos = nullptr;
	nodo *home = nullptr;
	nodo *end = nullptr;

	lista()
	{
		pos = home = end = new nodo( ' ' );
	}

	void insert( char c )
	{
		if ( !home )
			home = end = pos = new nodo( c );
		else
		{
			nodo *aux = new nodo( c );
			aux->next = pos->next;

			pos->next = aux;
			
			if ( pos == end)
				end = aux;
			pos = aux;
		}
	}

	void move( bool is_home )
	{
		if( is_home )
			pos = home;
		else
			pos = end;
	}

	string imp()
	{
		string ans;
		nodo *aux = home->next;
		while( aux )
		{
			ans.push_back( aux->c );
			aux = aux->next;
		}
		return ans;
	}

	void clear()
	{
		nodo *aux;
		pos = end = nullptr;

		aux = home;
		home = home->next;
		delete aux;

		while( home )
		{
			aux = home;
			home = home->next;
			delete aux;
		}
	}
};

int main()
{
	lista mi_lista;
	string cad;

	while( cin >> cad )
	{
		mi_lista = lista();
		for (int i = 0; i < cad.size(); ++i)
		{
			if ( cad[ i ] == '[' || cad[ i ] == ']')
				mi_lista.move( cad[ i ] == '[' );
			else
				mi_lista.insert( cad[ i ] );
		}

		cout << mi_lista.imp() << '\n';
		mi_lista.clear();
	}
	return 0;
}