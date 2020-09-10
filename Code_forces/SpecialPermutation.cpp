#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100000
#define mod(x) (((x%md) + md) % md)
#define p_b(k) push_back(k)
#define mid(i,j) ((i+j)>>1)
#define l(p) (p<<1)
#define r(p) ((p<<1)+1)
#define LSOne(n) (n&(-n))

using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;

bitset <maxn> usado;
int arr[ ] = {4, 3, 2, -2, -3, -4};

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);

	ll t, n;
	cin >> t;

	bool ban;
	while ( t-- )
	{
		cin >> n;
		usado.reset();
		
		ll current = n;
		while( usado.count() < n )
		{

			for( int i = 0; i < 6; ++i)
			{
				ban = false;
				if( current + arr[ i ] <= n && current + arr[ i ] > 0 && !usado[ current + arr[ i ] ] )
				{
					usado[ current + arr[ i ] ] = true;
					current += arr[ i ];

					cout << current << ' ';
					ban = true;
					break;
				}

			}

			if( !ban )
			{
				cout << -1 << '\n';
				break;
			}
		}

		cout << '\n';
	}

	return 0;
}


