#include <bits/stdc++.h>
#define maxn 200007

using namespace std;
typedef pair <int, int> pii;

pii arr[ maxn ];

int main( )
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[ i ].first;
		arr[ i ].second = i;
	}

	

	return 0;
}