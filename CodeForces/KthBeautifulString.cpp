#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ll t, n, k;
	ll pos1 = 1, pos2;

	cin >> t;

	while( t-- )
	{
		cin >> n >> k;
		pos1 = 1;
		while( pos1*(pos1+1) / 2 < k )
			++pos1;

		pos2 = k - ((pos1-1) * pos1 / 2);
		pos2--;

		//cout << pos1 << ' ' << pos2 << endl;
		for (int i = n-1; i >= 0; --i)
			if ( i == pos1 || i == pos2 )
				cout << 'b';
			else
				cout << 'a';
		cout << '\n';
	}
	return 0;
}	