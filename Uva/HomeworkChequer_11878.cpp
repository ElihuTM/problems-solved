#include <bits/stdc++.h>

using namespace std;

bool is_correct( string cad )
{
	if( cad.back() == '?' )
		return false;
	
	int a = 0, b = 0, c = 0, it = 0;
	char sig;

	while( cad[ it ] != '-' && cad[ it ] != '+' )
	{
		a = a*10 + cad[ it ] - '0';
		++it;
	}
	sig = cad[ it ];
	++it;
	while( cad[ it ] != '=' )
	{
		b = b*10 + cad[ it ] - '0';
		++it;
	}
	++it;
	while( it < cad.size() )
	{
		c = c*10 + cad[ it ] - '0';
		++it;
	}
	if( sig == '-' )
		b *= -1;
	
	return a+b == c;
}

int main()
{
	string aux;
	int ans = 0;

	while( getline( cin, aux ) )
		if( is_correct( aux ) )
			++ans;

	cout << ans << '\n';
	return 0;
}
