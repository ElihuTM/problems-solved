#include <bits/stdc++.h>
#define maxn 100005
#define inf 1000000007

using namespace std;

int ans[ maxn ];
int arr[ maxn ];

int main()
{
	cout << inf << endl;
	int n, maxi = -1, mini = inf, pos;
	cin >> n;

	for( int i = 0; i < n; ++i )
	{
		cin >> arr[ i ];
		if( arr[ i ] > maxi )
		{
			maxi = arr[ i ];
			pos = i;
		}
		if( arr[ i ] < mini )
			mini = arr[ i ];
	}

	if( mini >= ceil( (double)maxi / 2.0 ) )
	{
		cout << -1;
		for( int i = 1; i < n; ++i)
			cout << " -1";
		cout << '\n';
	}
	else
	{
		for( int  i = 0; i < n; ++i )
			if( arr[ (pos+i) % n ] < ceil( (double)maxi / (double)2.0 ) )
			{
				ans[ pos ] = i;
				break;
			}

		for( int i = (pos+n-1)%n; i != pos; i = (i+n-1)%n )
		{
			if( arr[ (i+1) % n ] < ceil( (double)arr[ i ] / (double)2.0 ) )
				ans[ i ] = 1;
			else
				ans[ i ] = ans[ (i+1)%n ] + 1;
		}

		cout << ans[ 0 ];
		for( int i = 1; i < n; ++i )
			cout << " " << ans[ i ];
		cout << '\n';
	}
	return 0;
}
