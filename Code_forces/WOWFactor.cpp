#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair < int, char> pic;

int main()
{
	string cad;
	vector < pic > arr;
	ll ans = 0;

	cin >> cad
	arr.emplace_back( 1, cad[ 0 ] );
	
	if( cad[ 0 ] == 'v' )
		++v;
	else
		++o;

	for( int i = 1; i < cad.size(); ++i )
	{
		if( cad[ i ] == 'v' )
			++v;
		else
			++o;

		if( cad[ i ] == cad[ i-1 ] )
			arr[ arr.size()-1 ].first++;
		else
		{
			arr.emplace_back( 1, cad[ i ] );
			if( arr.back().second == 'v' && arr.back().first == 1 )
			{
				arr.pop_back();
				--v;
			}
		}
	}

	if( cad[ 0 ] == 'o' )
		o -= arr[ 0 ].first;

	for( int i = arr[ 0 ].second == 'o'; i < arr.size()-1; i += 2 )
	{
		if( arr[ i ].first == 1 )
			continue;

		ll os = arr[ i+1 ].first;
		ll vs = v - arr[ i ].first;

		for( int j = i+2; j < arr.size(); ++j )
		{
			ans += (arr[ i ].first-1)*vs*os;
			vs -= arr[ j ];
		}
	}
	//for( int i  = 0; i < arr.size(); ++i )
	//	cout << arr[ i ].second << ": " << arr[ i ].first << "   ";
	return 0;
}
