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

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	int n;
	string opcion;
	ll p1, p2,
		plates;

	cin >> n;
	while( n ) {
		
		p1 = p2 = 0;
		while( n-- ){
			cin >> opcion >> plates;

			if( opcion == "DROP" ) {
				cout << "DROP 1 " << plates << endl;
				p1 += plates;
			}
			else {
				if( p2 >= plates ) {
					cout << "TAKE 2 " << plates << endl;
					p2 -= plates;
				}
				else {
					
					if( p2 > 0 ) {
						cout << "TAKE 2 " << p2 << endl;
						plates -= p2;
					}

					cout << "MOVE 1->2 " << p1 << endl;
					p2 = p1;
					p1 = 0;
					cout << "TAKE 2 " << plates << endl;
					p2 -= plates;
				}
			}
		}

		cin >> n;
		if( n ) cout << endl;
	}

	return 0;
}