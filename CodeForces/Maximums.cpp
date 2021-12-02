#include <bits/stdc++.h>

using namespace std;

int arr[ 200027 ];

int main()
{
	int n, maximus;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

	maximus = arr[ 0 ];
	cout << arr[ 0 ];

	for (int i = 1; i < n; ++i)
	{
		cout << ' ' << arr[ i ] + maximus;
		maximus = max( maximus, arr[ i ]+maximus );
	}
	cout << '\n';
	return 0;
}