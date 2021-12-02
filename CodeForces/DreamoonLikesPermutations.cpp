#include <bits/stdc++.h>
#define maxn 200007

using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;

vector<bool> pi;
vector<bool> pir;
vector<bool> cont;
vector<int> arr;

int main()
{
	int t,n;

	cin >> t;
	while( t-- )
	{
		cin >> n; n++;

		pi = vb( n, 0 );
		pir = vb( n, 0 );
		cont = vb( n, 0 );
		arr = vi( n, 0 );

		for (int i = 1; i < n; ++i)
			cin >> arr[ i ];

		int maxi = 0, contador = 0;
		for (int i = 1; i < n; ++i)
		{
			if ( arr[ i ] > maxi )
				maxi = arr[ i ];

			if ( !cont[ arr[ i ] ] )
			{
				cont[ arr[ i ] ] = true;
				++contador;
			}
			if ( contador == maxi && contador == i )
				pi[ i ] = true;
		}

		maxi = 0, contador = 0;
		cont = vb( n+1, 0 );

		for (int i = n-1; i > 0; --i)
		{
			if ( arr[ i ] > maxi )
				maxi = arr[ i ];

			if ( !cont[ arr[ i ] ] )
			{
				cont[ arr[ i ] ] = true;
				++contador;
			}

			if ( contador == maxi && contador == n-i )
				pir[ i ] = true;
		}

		vi ans;
		for (int i = 1; i < n-1; ++i)
		{
			if ( pi[ i ] && pir[ i+1 ] )
				ans.push_back( i );
		}

		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[ i ] << ' ' << n-ans[ i ]-1 << '\n';
		
	}
	return 0;
}	