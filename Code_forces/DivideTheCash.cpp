#include <bits/stdc++.h>

using namespace std;

int arr[ 50 ];

int main()
{
	int n, k, sum 	= 0;
	int cant;
	
	scanf( "%d %d", &n, &k );
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[ i ];
		sum += arr[ i ];
	}
	cant = k / sum;

	for (int i = 0; i < n; ++i)
	{
		printf("%i\n", arr[ i ]*cant );
	}

	return 0;
}
