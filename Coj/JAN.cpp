#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{

	int n;
	cin >> n;

	//for (int i = 1; i <= n; ++i)
	//{
		priority_queue <int, vector<int>, greater<int> > pq;
		//cout << i << " : ";
		int ans = 0;

		for (int j = 1; j <= n; ++j)
			pq.push( j );
		
		while( !pq.empty() )
		{
			int front = pq.top(); pq.pop();
			if ( front == 1)
				continue;

			if( front&1 )
			{
				pq.push( front-1 );
				ans++;
			}
			if( front%2 == 0)
			{
				pq.push( front/2 );
				pq.push( front/2 );
			}
		}
		cout << ans << endl;
	//}

	long long arr[ 33 ];
	arr[ 0 ] = 0;

	for (int i = 1; i < 33; ++i)
	{
		arr[ i ] = ((ll)(1<<i)*((1<<i)-1))/2;
		cout << arr[ i ] << " ";
	}

	cout << endl;
	for (int i = 1; i < 33; ++i)
	{
		arr[ i ] += arr[ i-1 ];
		cout << arr[ i ] << " ";
	}


	return 0;
}