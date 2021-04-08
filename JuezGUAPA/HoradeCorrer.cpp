#include <bits/stdc++.h>

using namespace std;

int main()
{	
	long long int n, m;
	cin >> n >> m;

	n *= m;
	for( int i = 10; i < 100; i += 10 )
	{
		cout << ceil((double)(i*n) / 100.0);

		if( i < 90 )
			cout << " ";
	}
	cout << endl;
	return 0;
}
