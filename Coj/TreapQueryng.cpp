#include <bits/stdc++.h>
#define maxn 2000003
#define endl '\n'

using namespace std;

bitset< maxn > criba;

struct node
{
	int key, value, primes, largest, size;
	node* left = nullptr;
	node* right = nullptr;

	node( int k, int s, int l ) : key( rand() ), value( k ), size( 1 ), primes( s ), largest( l ) { }
};
typedef pair< node*, node* > pnn;

inline int largest( node* x )
{
	return ( x ? x->largest : -1 );
}

inline int primes( node* x )
{
	return ( x ? x->primes : 0 );
}

inline int size( node* x )
{
	return ( x ? x->size : 0 );
}

inline node* update( node* x )
{
	if( x )
	{
		x->size = size( x->left ) + size( x->right ) + 1;
		x->largest = max( (criba[ x->value ] ? -1 : x->value ), max( largest( x->left), largest( x->right) ) );
		x->primes = primes( x->left ) + primes( x-> right ) + criba[ x->value ]; 
	}

	return x;
}

node* merge( node* u, node* v )
{
	if ( !u || !v )
		return ( u ? u : v );

	if ( u->key > v->key )
	{
		u->right = merge( u->right, v );
		return update( u );		
	}
	else
	{
		v->left = merge( u, v->left );
		return update( v );
	}
}

pnn split( node* u, int k )
{
	if( !u )
		return make_pair( nullptr, nullptr );

	if ( size(u->left) >= k)
	{
		pnn aux = split( u->left, k );
		u->left = aux.second;
		return make_pair( aux.first, update( u ) );
	}
	else
	{
		pnn aux = split( u->right, k - size(u->left) - 1 );
		u->right = aux.first;
		return make_pair( update( u ) , aux.second );
	}
}

void llenar()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = 0;

	for (int i = 4; i < maxn; i+=2 )
		criba[ i ] = false;

	for (long long i = 3; i < maxn; i += 2 )
		if ( criba[ i ] )
			for ( long long j = i*i; j < maxn; j += i)
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
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	llenar();

	node* treap = nullptr;
	int n, k, a, b, c;

	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		b = criba[ a ];
		c = b ? -1 : a;

		treap = merge(treap, new node( a,b,c ) );
	}

	//prin( treap );
	//cout << endl;

	pnn aux1;
	pnn aux2;
	int ans;

	for (int i = 0; i < k; ++i)
	{
		cin >> a >> b >> c;
		if ( a == 1)
		{
			aux1 = split( treap, b-1 );
			aux2 = split( aux1.second, 1 );

			//cout << " a == 1: \n";
			//prin( aux1.first );
			//cout << endl;

			a = criba[ c ];
			b = a ? -1 : c;

			treap = merge( aux1.first, new node( c,a,b ) );
			treap = merge( treap, aux2.second );

			delete( aux2.first );
		}
		else
		{
			aux1 = split( treap, c );
			aux2 = split( aux1.first, b-1 );

			//cout << " a != 1: \n";
			//prin( aux2.second );
			//cout << endl;

			if( a == 2 )
				cout << primes(aux2.second) << endl;
			else
			{
				if ( aux2.second->largest == -1)
					cout << "NO ANSWER\n";
				else
					cout << largest(aux2.second) << endl;
			}
			treap = merge( aux2.first, aux2.second );
			treap = merge( treap, aux1.second );

		}
		//cout << endl;
	}
	return 0;
}