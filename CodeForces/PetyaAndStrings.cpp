#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a, b;
	cin >> a;
	cin >> b;

	int len = a.size();
	for( int i = 0; i < len; ++i )
	{
		if( tolower( a[ i ] ) < tolower( b[ i ] ) )
		{
			cout << "-1\n";
			return 0;
		}
		else if( tolower( a[ i ] ) > tolower( b[ i ] ) )
		{
			cout << "1\n";
			return 0;
		}
	}
	cout << "0\n";
	return 0;
}
