#include <iostream>

using namespace std;

bool sum( int n )
{
	int ans = 0;
	while( n )
	{
		ans += n % 10;
		n /= 10;
	}

	return ans % 4 == 0;
}

int main()
{
	int n;
	cin >> n;

	while( !sum( n ) )
		++n;
	
	cout << n << '\n';

	return 0;
}
