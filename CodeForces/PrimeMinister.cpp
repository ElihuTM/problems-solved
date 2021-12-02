#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,a, ma;
	int sum = 0;
	int llevo = 0;
	vector <int> arr;

	cin >> n;
	
	cin >> a;
	arr.push_back( 1 );
	sum = llevo = ma = a;

	for( int i = 1; i < n; ++i )
	{
		cin >> a;
		if( 2*a <= ma )
		{
			llevo += a;
			arr.push_back( i+1 );
		}

		sum += a;
	}

	if( llevo > sum/2 )
	{
		cout << arr.size() << endl;
		for( int i = 0; i < arr.size(); ++i )
		{
			cout << arr[ i ];
			if( i < arr.size()-1 )
				cout << " ";
		}
		cout << endl;
	}
	else
		cout << "0\n";

	return 0;
}
