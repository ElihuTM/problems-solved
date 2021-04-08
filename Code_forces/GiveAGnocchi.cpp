#include <bits/stdc++.h>
#define maxn 5000003
#define p_b(a) push_back(a)

using namespace std;
typedef long long ll;

ll criba[ maxn ];
int n, k;

void llena()
{
	memset( criba, -1, sizeof criba );
	for (ll i = 2; i < maxn; ++i )
		if ( criba[ i ] == -1 )
			for (ll j = i*i; j < maxn; j+=i)
				if( criba[ j ] == -1 )
					criba[ j ] = i;
}

int main()
{
	llena();
	cin >> n >> k;

	int pos = 0;
	while( k )
	{
		if ( criba[ pos ] > n )
			--k;
		++pos;
	}

	cout << pos-1 << '\n';
	return 0;
}