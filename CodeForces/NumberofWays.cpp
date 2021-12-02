#include <bits/stdc++.h>
#define maxn 500005

using namespace std;
typedef long long ll;

ll arr[ maxn ];
int cont[ maxn ];

int main()
{
	int n;
	ll sum = 0;
	cin >> n;
	memset( cont, 0, sizeof cont );

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[ i ];
		sum += arr[ i ];
	}

	if ( sum%3 )
		cout << "0\n";
	else
	{
		ll part = sum/3;
		ll aux = 0;
		for (int i = n-1; i >= 0 ; --i)
		{
			aux += arr[ i ];
			cont[ i ] = cont[ i+1 ] + ( aux == part );
		}

		ll ans = 0;
		aux = 0;
		for (int i = 0; i < n-1	; ++i)
		{
			aux += arr[ i ];
			if ( aux == part )
				ans += cont[ i+2 ];
		}

		cout << ans << '\n';
	}
	return 0;
}