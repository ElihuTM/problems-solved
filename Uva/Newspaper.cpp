#include <bits/stdc++.h>
#define maxn 256

using namespace std;

int main()
{
	int casos, t, camb;
	int arr[ maxn ];
	long long ans;
	string cad;
	char c;

	cin >> casos;
	while( casos-- )
	{
		memset( arr, 0, sizeof arr);
		ans = 0;

		cin >> t;
		for( int i = 0; i < t; ++i )
		{
			cin >> c >> camb;
			if( c >= 0 && c < 256 )
				arr[ c ] = camb;
		}

		cin >> t;
		getline( cin, cad );
		while( t-- )
		{
			getline( cin, cad );
			for( int i = 0; i <cad.size(); ++i )
				if( cad[ i ] >= 0 && cad[ i ] < 256 )
					ans +=	arr[ cad[ i ] ];
		}
	
		cout << ans / 100 << '.';
		if( ans%100 < 10 )
			cout << 0;
		cout << ans%100 << "$\n";
	}
	return 0;
}
