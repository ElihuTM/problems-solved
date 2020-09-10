#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 103
#define md(x) (((x%mod) + mod) % mod)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

struct node
{
	string value;
	node* next = nullptr;

	node( string cad ) {
		value = cad;
	}
};

node* position;

struct lista
{
	node* front = nullptr;
	node* back = nullptr;
	int size = 0;

	string erase( int k )
	{
		//cout << "---------------\n";
		//cout << position->value << endl;
		vvi players( 2 );

		if( size == 1 )
		{
			string ans = front->value;
			remove_next( front );

			return ans;
		}

		k = (( k % size ) - 2 + size) % size;

		int cont = 0;
		while( cont < k )
		{
			position = position->next;
			++cont;
		}

		
		string ans = position->next->value;
		remove_next( position );
		position = position->next;
		
		//cout << position->value << endl;
		//cout << "---------------\n";

		return ans;
	}

	void remove_next ( node* x )
	{
		if( size == 1 )
		{
			node* aux = front;			
			front = back = nullptr;
			delete( aux);
		}
		else
		{
			node* aux = x->next;
			x->next = x->next->next;
		
			if( aux == front )
				front = front->next;
			if( aux == back )
				back = x;

			delete( aux );
		}

		--size;
	}
	void add( node* x )
	{
		if( !front )
		{
			front = back = x;
			front->next = x;
			back->next = x;
		}
		else
		{
			back->next = x;
			x->next = front;
			back = back->next;
		}
		++size;
	}

};

int input( )
{
	string cad;	
	getline( cin, cad );
	stringstream ss;

	ss << cad;
	int cont = 0;
	while( ss >> cad )
		++cont;

	return cont;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	int n, m;
	string cad;
	lista mylist;

	m = input();
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> cad;
		mylist.add( new node( cad ) );
	}
		
	position = mylist.front;
	bool equipo = 0;

	vector< vector< string > > players( 2 );
	while( mylist.size > 0 )
	{
		players[ equipo ].push_back( mylist.erase( m ) );
		equipo = 1 - equipo;
	}

	cout << players[ 0 ].size() << endl;
	for ( string c: players[ 0 ] )
		cout << c << endl;
	
	cout << players[ 1 ].size() << endl;
	for ( string c: players[ 1 ] )
		cout << c << endl;
	return 0;
}