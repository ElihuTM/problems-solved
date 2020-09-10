#include <iostream>

using namespace std;

int main()
{
	int t, ans;
	long long n;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		ans = 0;

		while( n )
		{
			++ans;
			n -= (n&(-n));
		}
		cout << ans-1 << '\n';
	}
	return 0;
}