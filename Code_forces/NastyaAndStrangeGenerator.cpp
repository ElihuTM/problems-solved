#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int arr[ maxn ];

bool cont( int &a, int fin )
{
	while( arr[ a ] < fin-1 )
	{
		if ( arr[ a+1 ] == arr[ a ]+1 )
			++a;
		else
		{
			//cout << "corto en " << a << endl;
			return false;
		}
	}
	return true;
}

bool is_pos( int n )
{
	int lim = n, ant;
	for (int i = 0; i < n; ++i)
	{
		//cout << "for con " << i << endl;
		ant = i;
		if ( cont( i, lim ) )
		{
			lim = arr[ ant ];
			//cout << "todo bien " << lim << endl;
		}
		else
		{
			//cout << "salio en " << i << endl;
			return false;
		}
	}

	return true;
}

int main()
{
	int t, n, a;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			arr[ a-1 ] = i;
		}

		if ( is_pos( n ) )
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}