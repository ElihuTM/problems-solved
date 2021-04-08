#include <bits/stdc++.h>
#define mod 1000000007
#define maxn 300005
#define ff first
#define ss second

using namespace std;
typedef long long ll;

string cad[ maxn ];

ll gen( string aux )
{
	ll ans = 0;
	for( int i = 0; i < aux.size(); ++i )
		ans = (ans * 10) + aux[ i ] - '0';
	
	return ans;
}

int main()
{
	bool is_sum = true;
	stack <ll> s;
	int n;

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> cad[ i ];

	for (int i = 0; i < n; ++i)
	{
		if ( cad[ i ] == "(")
		{
				s.push( -1 );
				is_sum = 1 - is_sum;
		}
		else if( cad[ i ] == ")" )
		{
			ll ans = 1 - is_sum;
			while( s.top() != -1 )
			{
				if( is_sum )
					ans += s.top();
				else
					ans *= s.top();

				ans %= mod;
				s.pop();
			}
			s.pop();

			is_sum = 1 - is_sum;
			s.push( ans );
		}
		else
			s.push( gen( cad[ i ] ) );
	}

	ll ans = 0;
	while( !s.empty() )
	{
		ans += s.top();
		ans %= mod;
		s.pop();
	}

	cout << ans << '\n';
	return 0;
}