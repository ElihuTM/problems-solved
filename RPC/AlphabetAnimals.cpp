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
	string cad,
	first_animal;

	vector< string > possible;
	vi reps( 30, 0);

	cin >> first_animal;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> cad;
		if( first_animal.back() == cad[ 0 ] )
			possible.push_back( cad );

		reps[ cad[ 0 ] - 'a' ]++;		
	}

	if( possible.empty() )
	{
		cout << "?" << endl;
		return 0;
	}

	for (int i = 0; i < possible.size(); ++i)
	{
		cad = possible[ i ];
		reps[ cad[ 0 ] - 'a']--;

		if( reps[ cad.back() - 'a' ] == 0 )
		{
			cout << cad << '!' << endl;
			return 0;
		}

		reps[ cad[ 0 ] - 'a' ]++;
	}

	cout << possible[ 0 ] << endl;
	return 0;
}