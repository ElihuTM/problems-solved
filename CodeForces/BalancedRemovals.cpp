#include <bits/stdc++.h>
#define maxn 50003
#define inf 1000000007

using namespace std;
typedef long long ll;

struct point
{
	ll x, y, z;
	int id;

	ll dist( point p )
	{
		return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y) + (z-p.z)*(z-p.z);
	}
};

point arr[ maxn ];
bool used[ maxn ];

int main()
{
	int n, ocu;
	ll dista, aux;
	cin >> n;
	memset( used, 0, sizeof used );

	for( int i = 0; i < n; ++i )
	{
		aux[ i ].id = i+1
		cin >> arr[ i ].x >> arr[ i ].y >> arr[ i ].z;
	}
	for( int i = 0; i < n; ++i )
	{
		if( used[ i ] ) continue;
		
		dista = inf;
		for( int j = i+1; j < n; ++j )
		{
			if( used[ j ] ) continue;

			aux = arr[ i ].dist( arr[ j ] );
			
			
			if( aux < dista )
			{
				dista = aux;
				ocu = j;
			}
		}
		
		used[ i ] = used[ ocu ] = true;
		cout << i+1 << " " << ocu+1 << '\n';
	}
	return 0;
}
