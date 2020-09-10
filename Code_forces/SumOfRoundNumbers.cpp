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

void imp( char x, int num )
{
	cout << x;
	for (int i = 0; i < num; ++i)
		cout << 0;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t;
	string n;

	cin >> t;
	while( t-- )
	{
		cin >> n;

		int cont = 0;
		for (int i = 0; i<n.size(); ++i)
			cont += (n[ i ] != '0');

		cout << cont << endl;
		imp( n[ 0 ], n.size()-1 );
		for (int i = 1; i < n.size(); ++i)
			if ( n[ i ] != '0')
			{
				cout << ' ';
				imp( n[ i ], n.size()-i-1 );
			}

		cout << endl;
	}

	return 0;
}
