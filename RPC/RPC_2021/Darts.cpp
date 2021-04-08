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

struct point
{
	ld x, y;
	point( ) : x( 0 ), y( 0 ) {}

	ld dist( point a ) {
		return (a.x - x)*( a.x - x) + ( a.y - y )*( a.y - y );
	}
};

const ld PI = acos(-1);

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int w, b, d, s, q, t;
	point p;
	point center;

	cin >> t;
	while( t-- )
	{
		cin >> w >> b >> d >> s;
		cin >> q;

		const ld angle = 360.0 / (ld)w;
		ld p_angle;

		int answer = 0, multi;
		while( q-- )
		{
			cin >> p.x >> p.y;

			ld distancia = center.dist( p );
			if( distancia <= b*b )
				answer += 50;
			else
			{
				p_angle = atan( p.y/p.x );
				if( p.x < 0 )
					p_angle += PI;
				else if( p.y < 0 )
					p_angle += 2*PI;

				p_angle = p_angle/PI*180;
				if( distancia < d*d )
					multi = 2;
				else if( distancia <= s*s )
					multi = 1;
				else
					multi = 0;

				answer += multi * (floor( p_angle / angle )+1);
			}		
		}
		cout << answer << endl;
	}



	return 0;
}