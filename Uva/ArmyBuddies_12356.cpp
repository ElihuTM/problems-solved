#include <bits/stdc++.h>

using namespace std;

set < int > arr;

void borrar( int l, int r )
{
	set< int >::iterator it;
	set< int >::iterator it2;
	
	it = arr.find( l );
	if( it == arr.begin() )
		cout << "* ";
	else
	{	
		--it;
		cout << *it << " ";
		++it;
	}
	
	while( it != arr.end() && *it <= r )
	{
		it2 = it;
		++it;
		arr.erase( it2 );
	}

	if( it == arr.end() )
		cout << "*\n";
	else
		cout << *it << '\n';
}

int main()
{
	int n, q, l, r;

	cin >> n >> q;
	while( n || q )
	{
		arr.clear();
		for( int i = 1; i <= n; ++i )
			arr.insert( i );

		while( q-- )
		{
			cin >> l >> r;			
			borrar( l, r );
		}
		cout << "-\n";

		cin >> n >> q;
	}
	return 0;
}
