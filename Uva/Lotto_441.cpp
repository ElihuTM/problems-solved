#include <bits/stdc++.h>

using namespace std;
typedef vector <int> vi;

int n;
vi arr;
vi ans;

void c_s( int pos, int cant )
{
	if( cant > 6 )
		return;
	
	//cout << "entro a : " << pos << " " << cant << endl;
	if( pos == n )
	{
		if( cant == 6 )
		{
			cout << ans[ 0 ];
			for( int i = 1; i < ans.size(); ++i )
				cout << " " << ans[ i ];
			cout << endl;
		}
		return;
	}

	ans.push_back( arr[ pos ] );
	c_s( pos+1, cant+1 );
	ans.pop_back();
	c_s( pos+1, cant );
}

int main()
{
	cin >> n;
	while( n )
	{
		arr.resize( n );
		for( int i = 0; i < n; ++i)
			cin >> arr[ i ];

		c_s( 0, 0 );
		
		cin >> n;
		
		if( n )
			cout << endl;
	}
	return 0;
}
