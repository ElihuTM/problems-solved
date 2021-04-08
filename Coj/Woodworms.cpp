//4150
#include <iostream>
#define maxn 1000003
#define endl '\n'

using namespace std;
typedef long long ll;

ll sum[ 2 ][ maxn ];
ll memo[ maxn ];
ll arr[ maxn ];

int main()
{
	ll tot = 0;
	int n;

	cin >> n;
	cin >> arr[ 0 ];

	sum[ 0 ][ 0 ] = arr[ 0 ];
	sum[ 1 ][ 0 ] = 0;

	for (int i = 1; i < n; ++i)
	{
		cin >> arr[ i ];
		sum[ 1 ][ i ] = sum[ 1 ][ i-1 ] + (arr[ i ] * (i&1) );
		sum[ 0 ][ i ] = sum[ 0 ][ i-1 ] + (arr[ i ] * (!(i&1)) );
	}
	/*
	cout << "par:\n";
	for (int i = 0; i < n; ++i)
		cout << sum[ 0 ][ i ] << " ";
	cout << "\nimpar:\n";
	for (int i = 0; i < n; ++i)
		cout << sum[ 1 ][ i ] << " ";
	cout << endl;
	*/
	if ( n&1 )
		cout << sum[ 0 ][ n-1 ] << " " << sum[ 1 ][ n-1 ] << endl;
	else
	{
		int j = n/2;
		int i = j-1;
		memo[ j ] = 0;
		
		while( i >= 0 )
		{
			bool ind = !(i&1);
			ll a = (i == 0 ? 0 : sum[ ind ][ i-1 ] );


			//cout << i << " " << j << endl;
			ll left  = arr[ j ] + sum[ ind ][ j-1 ] - a;
			ll right = arr[ i ] + sum[ !ind ][ j ] - sum[ !ind ][ i ];
			ll mid = arr[ j ] + arr[ i ] + tot - memo[ i+1 ];
			/*
			cout << "\t" << left << endl;
			cout << "\t" << mid << endl;
			cout << "\t" << right << endl;
			*/
			tot += (arr[ j ] + arr[ i ]);
			memo[ i ] = max( max(left, mid), right );

			i--;
			j++;
		}

		cout << memo[ i+1 ] << " " << tot - memo[ i+1 ] << endl;
	}
	return 0;
}