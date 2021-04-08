#include <bits/stdc++.h>
#define maxn 2000003

using namespace std;

struct node
{
	int key, value, size, max;
	node* left = nullptr;
	node* right = nullptr;

	node( int k ) : key( rand() ), value( k ), size( 1 ), max( k ) {}
};
typedef pair< node* , node* > pnn;

inline int size( node* x){
	return ( x ? x->size : 0 );
}

inline int mx( node* x ){
	return ( x ? x->max : -1 );
}

inline node* update( node* u )
{
	if ( u )
	{
		u->max = max( u->value, max(mx( u->left ), mx( u->right ) ) );
		u->size = size( u->left ) + size( u->right ) + 1;
	}
	return u;
}

node* merge( node* u, node* v )
{
	if ( !u or !v )
		return ( u ? u : v );

	if ( u->key > v->key )
	{
		u->right = merge(u->right, v );
		return update( u );
	}

	v->left = merge( u, v->left );
	return update( v );
}

pnn split(node* u, int k )
{
	if ( !u )
		return make_pair(nullptr, nullptr);

	if ( size(u->left) >= k )
	{
		pnn p = split( u->left, k );
		u->left = p.second;
		return make_pair(p.first, update(u));
	}
	else
	{
		pnn p = split(u->right, k - size(u->left)-1 );
		u->right = p.first;
		return make_pair( update(u), p.second );
	}
}

bitset< maxn > criba;

void llenar(){

	criba.set();
	criba[ 0 ] =  criba[ 1 ] = false;

	for (int i = 4; i < maxn; i += 2)
		criba[ i ] = false;

	for (long long i = 3; i < maxn; i+=2 )
		if ( criba[ i ])
			for ( long long j = i*i; j < maxn; j+=i )
				criba[ j ] = false;

}

void prin(node* x)
{
	if (x)
	{
		prin(x->left);
		cout<<x->value<<" ";
		prin(x->right);
	}
}

int main()
{
	llenar();

	int n, m, a, b, c, ans;
	node* treap = nullptr;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		if ( criba[ a ] )
			treap = merge(treap, new node( a ) );		
		else
			treap = merge(treap, new node( -1 ) );
	}
	
	pnn aux1, aux2;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b >> c;
		if ( a == 2 )
		{
			aux1 = split( treap, b );
			aux2 = split( aux1.second, c-b+1 );

			ans = mx(aux2.first);

			if ( ~ans )
				cout << ans << endl;
			else
				cout << "Vuelvo al rato\n";

			treap = merge( aux1.first, aux2.first );
			treap = merge( treap, aux2.second );
		}
		else
		{
			aux1 = split( treap, b );
			aux2 = split( aux1.second, 1 );

			if ( !criba[ c ] )
				c = -1;
			
			treap = merge( aux1.first, new node( c ) );
			treap = merge( treap, aux2.second );

			delete( aux2. first );
		}
	}

	return 0;
}