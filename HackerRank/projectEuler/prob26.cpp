#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool is_pal( string n )
{
	int i = 0, j = n.size()-1;
	while( i < j )
	{
		if( n[ i ] != n[ j ] )
			return false;

		++i;
		--j;
	}

	return true;
}

string to_s( int n )
{
	string cad;
	while( n )
	{
		cad.push_back( (n%10) + '0' );
		n /= 10;
	}

	return cad;
}

string camb_base( int i, int b )
{
	string ans;
	while( n )
	{
		ans.push_back( (n%b)+'0' );
		n /= b;
	}

	return ans;
}

int main()
{
	int n, b;
	ll ans = 0;

	cin >> n >> b;
	for( int i = 1; i < n; ++i )
		if( is_pal( to_s( i ) ) && is_pal( camb_base( i, b ) ) );
			ans += i;

	cout << ans << '\n';
	return 0;
}
