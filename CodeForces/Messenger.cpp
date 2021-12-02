#include <bits/stdc++.h>
#define ff first
#define ss second
#define mod 1000000007
#define maxn 200005
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

ll t[maxn], p[ maxn ]; // T = text, P = pattern
ll b[maxn], n, m; // b = back table, n = length of T, m = length of P
vpii text;
vpii pattern;

void kmpPreprocess() { // call this before calling kmpSearch()
	int i = 0, j = -1; b[0] = -1; // starting values
	while (i < m) { // pre-process the pattern string P
		while (j >= 0 && p[i] != p[j]) j = b[j]; // different, reset j using b
	i++; j++; // if same, advance both pointers
	b[i] = j; // observe i = 8, 9, 10, 11, 12, 13 with j = 0, 1, 2, 3, 4, 5
} } // in the example of P = "SEVENTY SEVEN" above

ll kmpSearch( pii front, pii last ) { // this is similar as kmpPreprocess(), but on string T
	int i = 0, j = 0;
	ll ans=0; // starting values
	while (i < n) { // search through string T
		while (j >= 0 && t[i] != p[j]) j = b[j]; // different, reset j using b
	i++; j++; // if same, advance both pointers
	if (j == m) { // a match found when j == m
		
		
		/*printf("P is found at index %d in T %d %d \n", i - j, i , j);
		cout << text[ i-j-1 ].ff << " " << text[ i-j-1 ].ss << endl;
		cout << text[ i-j+m ].ff << " " << text[ i-j+m ].ss << endl;

		cout << front.ff << " " << front.ss << endl;
		cout << last.ff << " " << last.ss << endl;
		*/
		if( i-j > 0 and i-j+m <= n-1 )
			if( text[ i-j-1 ].ss == front.ss && text[ i-j-1 ].ff >= front.ff )
				if( text[ i-j+m ].ss == last.ss && text[ i-j+m ].ff >= last.ff )
					++ans;

		j = b[j]; // prepare j for the next possible match
	}}

	return ans;
}

pii make_my_pair( string cad ) {
	pii answer;
	answer.ss = cad.back() - 'a' + 1;
	answer.ff = 0;

	int pos = 0;
	while( cad[ pos ] != '-' ) answer.ff = answer.ff*10 + cad[ pos++ ] - '0';

	return answer;
}

vpii compres( vpii a ) {
	vpii ans;
	int len = 0;
	ans.push_back( a.front() );

	for (int i = 1; i < a.size(); ++i)
	{
		if ( ans[ len ].ss == a[ i ].ss )
			ans[ len ].ff += a[ i ].ff;
		else
		{
			ans.push_back( a[ i ] );
			++len;
		}
	}

	return ans;
}

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);	

	cin >> n >> m;
	string cad;

	text.resize( n );
	pattern.resize( m );
	for (int i = 0; i < n; ++i) {
		cin >> cad;
		text[ i ] = make_my_pair( cad );
	}

	for (int i = 0; i < m; ++i) {
		cin >> cad;
		pattern[ i ] = make_my_pair( cad );
	}

	text = compres( text );
	pattern = compres( pattern );

	n = text.size();
	m = pattern.size();

	ll ans = 0;
	if( m < 2 )
	{
		if( m == 2 )
		{
			pii front = pattern.front();
			pii last = pattern.back();

			for (int i = 0; i < n-1; ++i)
			{
				if( text[ i ].ss == front.ss && text[ i ].ff >= front.ff ) {
					if( text[ i+1 ].ss == last.ss && text[ i+1 ].ff >= last.ff )
						++ans;
				}
			}
		}
		else {
			pii front = pattern.front();
			for (int i = 0; i < n; ++i)
			{
				if( text[ i ].ss == front.ss && text[ i ].ff >= front.ff ) {
					ans += text[ i ].ff - front.ff + 1;
				}
			}
		}
	}
	else {
		pii front = pattern.front();
		pii last = pattern.back();
		m -= 2;

		for (int i = 0; i < n; ++i)
			t[ i ] = text[ i ].ff * text[ i ].ss;

		for (int i = 0; i < m; ++i)
			p[ i ] = pattern[ i+1 ].ff * pattern[ i+1 ].ss;

		kmpPreprocess();
		ans = kmpSearch( front, last );
	}

	cout << ans << endl;
	return 0;
}