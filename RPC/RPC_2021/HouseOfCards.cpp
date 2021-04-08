#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cout << i << ": " << 3*i*(i+1)/2 - i;

		if ( (3*i*(i+1)/2 - i) % 4 == 0)
			cout << "  Divisible\n";
		else
			cout << endl;
	}
	
	return 0;
}