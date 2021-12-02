#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100005
#define mod(x) (((x%md) + md) % md)
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
	
	ll t;
	string cad;

	cin >> t;
	while( t-- )
	{
		cin >> cad;
		cout << cad[ 0 ];
		for (int i = 1; i < cad.size(); i+=2 )
			cout << cad[ i ];

		cout << endl;

	}

	return 0;
}
