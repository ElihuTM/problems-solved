#include <bits/stdc++.h>
#define maxn 100007

using namespace std;
typedef long long ll;

ll arr[ maxn ];
ll a,b,c;
int casos,n,q;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );


	cin >> casos;
	while( casos-- )
	{
		cin >> n >> q;

		cin >> arr[ 0 ];
		for (int i = 1; i < n; ++i)
		{
			cin >> arr[ i ];
			arr[ i ] += arr[ i-1 ];
		}

		for (int i = 0; i < q; ++i)
		{
			cin >> a >> b;
			if ( a > b )
			{
				c = a;
				a = b;
				b = c;
			}

			if ( a )
				a = arr[ a-1 ];

			cout << arr[ b ] - a << "\n";
		}

		if (casos)
			cout << "\n";
	}
	return 0;
}