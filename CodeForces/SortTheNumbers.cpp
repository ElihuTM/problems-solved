#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector< long long > arr( n );
	for( int i=0; i<n; ++i)
		cin >> arr[ i ];

	sort( arr.begin(), arr.end() );

	for( int i=0; i<n; ++i )
	{
		cout << arr[ i ];
		if( i<n-1 )
			cout << ' ';
		else
			cout << '\n';
	}
	return 0;
}
