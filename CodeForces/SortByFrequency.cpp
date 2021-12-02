#include <bits/stdc++.h>

using namespace std;

pair <int, char > arr[ 27 ];

int main()
{
	string cad;

	cin >> cad;
	for( int i = 0; i < 27; ++i )
	{
		arr[ i ] = make_pair( 0, 'a'+i);
	}

	for (int i = 0; i < cad.size(); ++i)
		arr[ cad[ i ]-'a' ].first--;

	sort( arr, arr+27 );
	for( int i = 0; i < 27; ++i)
	{
		for( int j = arr[ i ].first; j < 0; ++j )
			cout << arr[ i ].second;
	}
	cout << '\n';
	return 0;
}