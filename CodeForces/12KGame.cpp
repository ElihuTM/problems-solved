#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, k, q;
	cin >> q;

	while( q-- )
	{
		cin >> n >> k;

		if( n < k || k%3 )
		{
			if( n % 3 )
				cout << "Alice\n";
			else
				cout << "Bob\n";
		}
		else
		{
			if( n ==  k )
				cout << "Alice\n";
			else
			{
				if( k == 3 )
				{
					if( n%4 )
						cout << "Alice\n";
					else
						cout << "Bob\n";
				}
				else 
				{
					if( n % 3 == 1 )
						cout << "Alice\n";
					else
						cout << "Bob\n";
				}
			}
		}
	}
	return 0;
}
