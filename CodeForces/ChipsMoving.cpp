#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, par = 0, impar = 0,x;
	cin >> n;
	
	while( n-- )
	{
		cin >> x;
		if( x&1 )
			++impar;
		else
			++par;
	}

	cout << min( par, impar ) << '\n';
}
