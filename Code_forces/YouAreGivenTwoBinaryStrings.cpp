#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int main()
{
	int t;
 	string a, b;

	cin >> t;
	while( t-- )
	{
		cin >> a >> b;
		int len1 = a.size();
		int len2 = b.size();
		
		int ind0 = 0;
		for( int i  = len2-1; i >= 0; --i)
			if( b[ i ] == '0' )
				++ind0;
			else break;

		int ans = 0;
		for( int i = len1 - ind0 - 1; i >= 0; --i )
			if( a[ i ] == '0' )
				++ans;
			else break;

		cout << ans << '\n';
	}
	return 0;
}
