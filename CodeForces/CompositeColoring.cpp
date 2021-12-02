#include <bits/stdc++.h>
#define maxn 1007

using namespace std;
typedef vector<int> vi;

int criba[ maxn ];

void llenar()
{
	criba[ 0 ] = 1;
	for (int i = 1; i < maxn; ++i)
		criba[ i ] = i;

	for (int i = 2; i < maxn; ++i)
		if ( criba[ i ] == i )
			for (int j = i*i; j < maxn; j+=i )
				if( criba[ j ] > i )
					criba[ j ] = i;
}

int main()
{
	llenar();

	int t, n, a, cont;
	map<int,int> answer;
	set<int> exist;
	vi ans;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		ans = vi( n );
		exist.clear();

		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			ans[ i ] = criba[ a ];
		}

		for (int i = 0; i < n; ++i)
			exist.insert( ans[ i ] );

		int k = 1;
		for (auto it : exist)
			answer[ it ] = k++;

		cout << exist.size() << '\n';
		for (int i = 0; i < n; ++i)
			cout << answer[ ans[ i ] ] << ' ';
		cout << '\n';	
	}
	return 0;
}