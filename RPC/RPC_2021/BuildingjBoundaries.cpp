#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 100005
#define md(x) (((x%mod) + mod) % mod)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

struct cube
{
	ll a, b;

	cube rotate()
	{
		cube ans;
		ans.a = b;
		ans.b = a;

		return ans;
	}
};

cube cubes[ 3 ][ 2 ];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	int querys;
	cin >> querys;

	while( querys-- )
	{
		for (int i = 0; i < 3; ++i)
		{
			cin >> cubes[ i ][ 0 ].a >> cubes[ i ][ 0 ].b;
			cubes[ i ][ 1 ] = cubes[ i ][ 0 ].rotate();
		}

		ll aux, ans1 = 0;
		for (int i = 0; i < 3; ++i)
			ans1 += cubes[ i ][ 0 ].a;
		ans1 *= max( cubes[ 0 ][ 0 ].b, max( cubes[ 1 ][ 0 ].b, cubes[ 2 ][ 0 ].b ) );

		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j)
				for (int k = 0; k < 2; ++k)
				{
					cube uno = cubes[ 0 ][ i ];
					cube dos = cubes[ 1 ][ j ];
					cube tres = cubes[ 2 ][ k ];

					aux = uno.a + dos.a + tres.a;
					aux *= max( uno.b, max( dos.b, tres.b ) );
					ans1 = min( ans1, aux );
				}

		cube copy[ 3 ][ 2 ];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 2; ++j)
				copy[ i ][ j ] = cubes[ i ][ j ];

		for (int x = 0; x < 3; ++x)
			for (int y = 0; y < 3; ++y)
				for (int z = 0; z < 3; ++z)
				{
					if( x == y or x == z or y == z )
						continue;

					cubes[ 0 ][ 0 ] = copy[ x ][ 0 ];
					cubes[ 0 ][ 1 ] = copy[ x ][ 1 ];
					
					cubes[ 1 ][ 0 ] = copy[ y ][ 0 ];
					cubes[ 1 ][ 1 ] = copy[ y ][ 1 ];

					cubes[ 2 ][ 0 ] = copy[ z ][ 0 ];
					cubes[ 2 ][ 1 ] = copy[ z ][ 1 ];
					
					for (int i = 0; i < 2; ++i)
						for (int j = 0; j < 2; ++j)
							for (int k = 0; k < 2; ++k)
							{
								cube uno = cubes[ 0 ][ i ];
								cube dos = cubes[ 1 ][ j ];
								cube tres = cubes[ 2 ][ k ];

								ll base = max( uno.a, dos.a );
								base += tres.a;

								ll altura = uno.b + dos.b;
								altura = max( altura, tres.b );

								ans1 = min( ans1, base*altura );
							}	
				}

		cout << ans1 << endl;	
	}
	return 0;
}