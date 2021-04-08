#include <bits/stdc++.h>
#define maxn 200007

using namespace std;
typedef long long ll;

int arr[ maxn ];

int main()
{
	int n,  m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	sort( arr, arr + n );

	vector< ll > xtr;
	int pos = 0;
	ll ans = 0;

	for (int i = 0; i < n; ++i)
	{
		if ( xtr.size() < m )
		{
			xtr.push_back( arr[ i ] );
			ans += arr[ i ];
		}
		else
		{
			ans += arr[ i ] + xtr[ pos ];
			xtr[ pos ] += arr[ i ];
			pos = (pos+1)%m;
		}
		
		cout << ans;

		if ( i < n-1 )
			cout << " ";
		else
			cout << endl;
	}

	return 0;	
}