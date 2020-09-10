#include <iostream>

using namespace std;

int main()
{
	int num, n, mod, ans;
	cin >> num;

	n = num / 1000;
	mod = num % 1000;

	ans = 1;
	for (int i = n; i > 0; i -= 2)
		ans = (ans*i) % mod;

	cout << ans << '\n';
	return 0;
}