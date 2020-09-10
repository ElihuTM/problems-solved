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
	ios_base::sync_with_stdio(0);
	cin.tie(0);	

	int n, q;
	ll a, maxi = 0;

	cin >> n;
	vi arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[ i ];
		maxi = max( maxi, arr[ i ] );
	}

	cin >> q;
	while( q-- )
	{
		cin >> a;

		if ( maxi > a )
		{
			cout << "Impossible" << endl;
			continue;
		}

		int cont = 0, sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if ( sum + arr[ i ] <= a )
			 	sum += arr[ i ];
			else
			{
				sum = arr[ i ];
				++cont;
			}
		}

		cout << cont+1 << endl;
	}
	return 0;
}
