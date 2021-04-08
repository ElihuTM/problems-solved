#include <bits/stdc++.h>

using namespace std;


int main()
{
	int n,k;

	cin >> n >> k;
	vector<int> arr(n);
	for( int i = 0; i < n; ++i )
		cin >> arr[ i ];

	sort( arr.rbegin(), arr.rend() );
		
	int ans = 0;
	if( arr[ k-1 ] == 0 )
	{
		ans = k-1;
		while( arr[ ans ] == 0 && ans >= 0 )
			--ans;
	}
	else
	{
		int lim = arr[ k-1 ];
		ans = k-1;
		while( ans < n-1 && arr[ ans+1 ] == lim)
			++ans;
	}
	cout << ans+1 << '\n';

	return 0;
}
