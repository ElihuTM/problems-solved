#include <bits/stdc++.h>
#define ff first
#define ss second
#define md 1000000007
#define maxn 100
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

char ans[ maxn ];
string cad;
vi sum;
vi dic;
int n, m;

void encuentra_ceros()
{
	vi ceros;
	for (int i = 0; i < m; ++i)
	{
		if ( sum[ i ] == 0)
			ceros.push_back( i );
	}

	int letra = 26;
	while( dic[ letra ] < ceros.size() )
		--letra;

	for (int i = 0; i < m; ++i)
	{
		if (sum[ i ] == -1 )
			continue;

		if ( sum[ i ] == 0 )
		{
			sum[ i ]  = -1;
			ans[ i ] = letra + 'a';
		}
		else
		{
			for (int j = 0; j < ceros.size(); ++j)
				sum[ i ] -= abs( i - ceros[ j ] );
		}
	}

	for (int i = letra; i < 27; ++i)
		dic[ i ] = 0;
}

bool se_pueda()
{
	for (int i = 0; i < m; ++i)
		if ( sum[ i ] > -1 )
			return true;

	return false;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	
	
	ll t;
	cin >> t;
	

	while( t-- )
	{
		cin >> cad;
		n = cad.size();
		cin >> m;

		dic = vi(27, 0);
		sum.resize( m );

		for (int i = 0; i < m; ++i)
			cin >> sum[ i ];

		for (int i = 0; i < n; ++i)
			dic[ cad[ i ]-'a']++;

		while( se_pueda() )
			encuentra_ceros();

		for (int i = 0; i < m; ++i)
			cout << ans[ i ];

		cout << endl;
	}

	return 0;
}
