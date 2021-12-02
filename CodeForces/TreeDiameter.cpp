#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second

using namespace std;
typedef vector < int > vi;
typedef pair <vi, vi> pvv;

pvv merge( pvv arr )
{
	pvv ans;
	int len1 = arr.ff.size();
	int len2 = arr.ss.size();

	for( int i = 0; i < len1; ++i )
	{
		if( i&1 )
			ans.ff.push_back( arr.ff[ i ] );
		else
			ans.ss.push_back( arr.ff[ i ] );
	}
	
	for( int i = 0; i < len2; ++i )
	{
		if( i&1 )
			ans.ff.push_back( arr.ss[ i ] );
		else
			ans.ss.push_back( arr.ss[ i ] );
	}

	return ans;
}

int main()
{
	int n, t, ans, aux;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		
		ans = 0;
		pvv arr;
		for( int  i = 1; i <= n; ++i )
		{
			if( i&1 )
				arr.ff.push_back( i );
			else
				arr.ss.push_back( i );
		}
	
		for( int i = 0; i < 9; ++i )
		{
			int len1 = arr.ff.size();
			int len2 = arr.ss.size(); 

			if( len1 && len2 )
			{
				cout << len1 << " " << len2 << " ";
				for( int i = 0; i < len1; ++i )
					cout << arr.ff[ i ] << " ";
		
				for( int i = 0; i < len2; ++i )
				{
					cout << arr.ss[ i ];
					if( i < len2-1 )
						cout << " ";
				}
				cout << endl;
				cout.flush();

				cin >> aux;
				if( aux > ans )
					ans = aux;
			}
			arr = merge( arr );
		}

		cout << "-1 " << ans <<endl;
	}
	return 0;
}
