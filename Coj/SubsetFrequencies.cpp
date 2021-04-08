#include <bits/stdc++.h>
#define maxn 1000003

using namespace std;

int arr[ maxn ];
int s[ 100 ];

struct par
{
	int f = 0;
	int s = 0;

	bool operator < (const par &p )const
	{
		return ( s > p.s || (s == p.s && f < p.f) );
	}

	int operator ++ ( int a )
	{
		s++;
		return s;
	}
};

par ans[ 100 ];

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n, k, cont;
	cin >> n >> k;

	for (int i = 0; i < n; ++i)
		cin >> arr[ i ];
	
	sort( arr, arr+n );

	for (int i = 0; i < k; ++i)
		cin >> s[ i ];

	int ini, fin, sum;
	for (int i = 0; i < k; ++i)
	{
		ans[ i ].f = s[ i ];
		cont = ini = 0; fin = n-1;

		while( ini < fin )
		{
			sum = arr[ ini ] + arr[ fin ];
			if ( sum == ans[ i ].f )
			{
				ans[ i ]++;
				++ini;
				--fin;
			}
			else if( sum < ans[ i ].f )
				++ini;
			else
				--fin;
		}
	}

	sort( ans, ans+k );
	for (int i = 0; i < k; ++i)
		cout << ans[ i ].f << " " << ans[ i ].s << endl;
	
	return 0;
}