#include <iostream>
#include <cstring>
#define maxn 50003
#define endl '\n'

using namespace std;
typedef long long ll;

ll ft[ maxn ];
int n;

inline int LSOne( int n )
{
	return n&(-n);
}

inline void adjust( int k, int value )
{
	for (; k <= n; k+=LSOne(k) )
		ft[ k ] += value;
}

inline ll query( int k )
{
	ll tot = 0;
	for (; k ; k -= LSOne(k) )
		tot += ft[ k ];
	return tot;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	memset( ft, 0, sizeof ft );
	int k, a, b, c, x;

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a;
		adjust( i, a );
	}

	for (int i = 0; i < k; ++i)
	{
		cin >> x >> a >> b;
		if ( x == 1 )
		{
			adjust( a, b );
			cout << "1 " << query( a ) - query( a-1 ) << endl;
		}
		else
		{
			if ( x&1 || x == 0)
				cout << "Error\n";
			else
			{
				if ( a > b )
				{
					c = a;
					a = b;
					b = a;
				}

				cout << x << " " << query( b ) - query( a-1 ) << endl;
			}
		}
	}


	return 0;
}
