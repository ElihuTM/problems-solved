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

const pii UNVISITED( -1, -1 );
const long long	first_street = 0;
long long last_street, n;
vpii road;

void read_input() {
	long long monuments,
			  x, y;

	cin >> n >> last_street;
	cin >> monuments;

	road.assign( n, UNVISITED );
	for (int i = 0; i < monuments; ++i) {
		cin >> x >> y;

		if( road[ x ] == UNVISITED )
			road[ x ] = pii( y, y );
		else {
			road[ x ].ff = min( road[ x ].ff, y );
			road[ x ].ss = max( road[ x ].ss, y );
		}
	}
}

long long cost_of_route( int y_street ) {
	long long answer = n;

	for (int i = 0; i < n; ++i)
		if( road[ i ] != UNVISITED ) {
			if( y_street >= road[ i ].ss ) {
				answer += (y_street - road[ i ].ff) * 2;
			}
			else if( y_street <= road[ i ].ff )
				answer += (road[ i ].ss - y_street ) * 2;
			else {
				answer += (road[ i ].ss - y_street) * 2;
				answer += (y_street - road[ i ].ff) * 2;
			}
		}

	return answer;
}

long long ternary_search ( long long lower_street, long long high_street ) {
	long long differrence_between_streets = high_street - lower_street;

	while( differrence_between_streets > 2 ) {
		const long long a_third = (high_street - lower_street ) / 3;
		const long long middle_street1 = lower_street + a_third;
		const long long middle_street2 = high_street - a_third;

		if( cost_of_route( middle_street1 ) < cost_of_route( middle_street2 ) )
			high_street = middle_street2;
		else
			lower_street = middle_street1;

		differrence_between_streets = high_street - lower_street;
	}

	const long long middle_street = (high_street + lower_street) / 2;
	long long answer = cost_of_route( lower_street );
			answer = min( answer, cost_of_route( high_street ) );
			answer = min( answer, cost_of_route( middle_street ) );

	return answer;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	read_input();

	const long long cheapest_cost = ternary_search( first_street, last_street );
	cout << cheapest_cost-1 << endl;
	return 0;
}