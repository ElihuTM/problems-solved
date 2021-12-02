#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
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

int arr[ maxn ];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	int t, n, min_value, max_value;

	cin >> t;
	while( t-- )
	{
		cin >> n;
		min_value = inf;
		max_value = -1;
		int original_diff = 0;

		cin >> arr[ 0 ];
		for( int i = 1; i < n; ++i)
		{
			cin >> arr[ i ];
			if( arr[ i-1 ] == -1 )
			{
				min_value = min( min_value, arr[ i ] );
				max_value = max( max_value, arr[ i ] );
			}
			else
			{
				original_diff 
			}
		}
		
		int current_diference = 0;
		for( int i = 1; i < n; ++i)
			if( arr[ i ] > 0 && arr[ i-1 ] > 0 )
				current_diference = max( current_diference, abs(arr[ i ] - arr[ i-1 ] ) );
		
		cout << max( current_diference, (min_value + max_value + 1) / 2 ) << '\n';
	}

	return 0;
}
