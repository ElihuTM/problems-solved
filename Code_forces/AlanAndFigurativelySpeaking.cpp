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
	
	map <char, char> transform;
	for (char i = 'a'; i <= 'z'; ++i)
		transform[ i ] = i;

	for (char i = 'A'; i <= 'Z'; ++i)
		transform[ i ] = i;

	transform[ 'o' ] = transform[ 'O' ] = '0';
	transform[ 'i' ] = transform[ 'I' ] = '1';
	transform[ 'z' ] = transform[ 'Z' ] = '2';
	transform[ 'e' ] = transform[ 'E' ] = '3';
	transform[ 'a' ] = transform[ 'A' ] = '4';
	transform[ 's' ] = transform[ 'S' ] = '5';
	transform[ 'g' ] = transform[ 'G' ] = '6';
	transform[ 't' ] = transform[ 'T' ] = '7';
	transform[ 'b' ] = transform[ 'B' ] = '8';
	transform[ '_' ] = '_';

	string cad;
	cin >> cad;

	for (int i = 0; i < cad.size(); ++i)
		cout << transform[ cad[ i ] ];
	cout << endl;
	return 0;
}