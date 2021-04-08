#include <bits/stdc++.h>

using namespace std;

int arr[ 50 ];

int main()
{
	int n, k;
	double cant;
	scanf( "%d %d", &n, &k );
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[ i ];
		sum += arr[ k ];
	}
	cant = k / sum;

	for (int i = 0; i < n; ++i)
	{
		printf("%.2lf\n", arr[ i ]*cant );
	}

	return 0;
}