#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll casos, a, b, n, len;
	//set <ll> dic;
	//vector <ll> fib;
	cin >> casos;

	while( casos-- )
	{
		cin >> a >> b >> n;

		if( n%3 == 0 )
			cout << a << '\n';
		else if( n%3 == 1 )
			cout << b << '\n';
		else 
			cout << (a^b) << '\n';
		/*dic.clear();
		fib.clear();

		fib.push_back( a );
		fib.push_back( b );
		
		dic.insert( a );
		dic.insert( b );

		while( dic.find( a^b ) == dic.end() )
		{
			fib.push_back( a^b );
			dic.insert( a^b );

			b = fib.back();
			a = fib[ fib.size()-2 ];
		}*/

		//cout << fib[ n%fib.size() ] << '\n';
	}
	return 0;
}
