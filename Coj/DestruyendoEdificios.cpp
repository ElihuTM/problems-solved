#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair < ll, ll> pii;

stack< pii > s;

pii s_top()
{
	if( s.empty() )
		return make_pair( 0,0 );
	
	pii ans = s.top(); s.pop();
	return ans;
}

inline bool orden(int a, int b, int c )
{
	return ( a >= b && b >= c);
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int n;
	ll a, ans = 0;

	pii top1, top2, top3;
	s.push( make_pair(0,0) );

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;

		if ( a > s.top().first )
			s.push( make_pair( a,1 ) );
		else
		{
			top1 = make_pair( a,1 );
			top2 = s_top();
			top3 = s_top();

			while( !orden( top1.first, top2.first, top3.first ) )
			{
				ans = max( ans, top2.first*top2.second );

				if( top1.first == top3.first )
				{
					top1.second += (top2.second + top3.second );
					top2 = s_top();
				}
				else
				{
					if( top3.first > top1.first )
					{
						top2.first = top3.first;
						top2.second += top3.second;
					}
					else
					{
						top1.second += top2.second;
						top2 = top3;
					}
				}
				top3 = s_top();
			}

			s.push( top3 );
			s.push( top2 );
			s.push( top1 );
		}
	}
	

	while( !s.empty() )
	{
		top1 = s_top();
		top2 = s_top();

		if ( top1.first == 0)
			break;

		ans = max( ans, top1.first*top1.second );

		top2.second += top1.second;
		s.push( top2 );
	}

	cout << ans << endl;
	return 0;
}
