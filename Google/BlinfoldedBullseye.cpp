#include <bits/stdc++.h>
#define maxn 1000000000

using namespace std;
typedef long long ll;
typedef pair <int,int> pii;

int x[] = { 1, -1, -1, 1 };
int y[] = { 1, 1, -1, -1 };
int cont;

int u_b1( ll i, ll j, int cord, int op )
{
	ll m;
	string ans;

	while( j-i > 1 )
	{
		m = i + (j-i) / 2;
		cout << cord * op * m << ' ' << ( 1-cord ) * op * m << '\n';
		++cont;

		cin >> ans;
		if ( ans == "HIT" )
			i = m;
		else
			j = m;
	}

	return j-1;
}

int main()
{
	int t,a,b;
	bool ban;
	string act;

	cin >> t >> a >> b;
	for (int c = 1; c <= t; ++c)
	{
		cont = 0;
		ban = false;
		int r = a;

		ll y1 = u_b1( -maxn+a, maxn, 0, 1 );
		ll y2 = u_b1( -maxn+a, maxn, 0, -1 );
		ll x1 = u_b1( -maxn+a, maxn, 1, 1 );
		ll x2 = u_b1( -maxn+a, maxn, 1, -1 );

		int midy = (y1+y2)/2 - y2;
		int midx = (x1+x2)/2 - x2;

		int mid = sqrt( 300-cont );
		mid /= 2;
		for (int i = midx-mid; i <= midx+mid; ++i)
		{
			for (int j = midy-mid; j <= midy+mid; ++j)
			{
				cout << i << ' ' << j << '\n';
				cout.flush();

				cin >> act;
				if ( act == "CENTER" )
				{
					ban = true;
					break;
				}
			}

			if ( ban )
				break;		
		}
	}
	return  0;
}