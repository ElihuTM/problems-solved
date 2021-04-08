#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, a;
	int mini = 1000000007;
	int maxi = 0;

	cin >> n;
	for( int i=0; i<n; ++i)
	{
		cin >> a;
		if( a < mini )
		       mini = a;
		if( a > maxi )
			maxi = a;

		cout << mini + maxi << endl;
	}
	return 0;
}
