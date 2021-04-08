#include <iostream>
#define maxn 100005

using namespace std;
typedef long long ll;

ll arr[ maxn ];

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n;
	ll s;

	while( cin >> n >> s )
	{
		for (int i = 0; i < n; ++i)
		cin >> arr[ i ];

		ll sum = arr[ 0 ];
		int i = 0, j = 0;

		while( sum != s and j < n )
		{
			if( sum > s )
			{
				if ( i == j )
				{
					j = ++i;
					sum = arr[ i ];
				}
				else
				{
					sum -= arr[ i ];
					++i;
				}
			}
			else
				sum += arr[ ++j ];
		}
		if ( j < n )
			cout << i+1 << " " << j+1 << endl;
		else
			cout << -1 << endl;
	}
	
	return 0;
}