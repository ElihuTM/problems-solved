#include <bits/stdc++.h>
#define maxn 104

using namespace std;

int arr[ maxn ];
bitset <maxn> oc;
int even[ 2 ];

int main()
{
	int n, ans = 0;
	even[ 0 ] = even[ 1 ] = 0;

	oc.reset();
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[ i ];
		oc[ arr[ i ] ] = true;
	}

	if ( oc.count() == 1 )
	{
		cout << "1\n";
		return 0;
	}

	for (int i = 1; i <= n ; ++i)
		if ( !oc[ i ] )
			++even[ (i&1) ];

	int ini = n-1;

	while( arr[ ini ] == 0 )
		--ini;

	for (int i = ini-1; i >= 0 ; --i)
	{
		if ( arr[ i ] != 0 ) {
			ans += ( (arr[ i ]+arr[ i+1 ])&1 );
		}
		else
		{
			if ( i == 0 || arr[ i-1 ] == 0)
			{
				if ( even[ (arr[ i+1 ]&1) ] == 0)
				{
					++ans;
					--even[ 1-(arr[ i+1 ]&1) ];
					arr[ i ] = arr[ i+1 ]-1;
				}
				else
				{
					
					--even[ (arr[ i+1 ]&1) ];
					arr[ i ] = arr[ i+1 ];
				}
			}
			else if( (arr[ i-1 ] + arr[ i+1 ])&1 )
			{
				arr[ i ] = arr[ i-1 ];
				++ans;
			}
			else
			{
				if ( even[ (arr[ i+1 ]&1) ] == 0)
				{
					++ans;
					--even[ 1-(arr[ i+1 ]&1) ];
					arr[ i ] = arr[i+1]-1;
				}
				else
				{
					--even[ (arr[ i+1 ]&1) ];
					arr[ i ] = arr[i+1];
				}
			}
		}
	}

	int con = n - ini - 1;
	ans += ( con > even[ arr[ini]&1 ] );
	
	cout << ans << '\n';
}
/*
10
1 3 5 7 9 2 4 6 8 10
1

10
1 0 0 4 4 4 5 0 0 0 0 0

0 1
2 3
ans = 1

10 
1 2 9 7 3 5 0 0 0 0

0 1
4 0
ans = 2

8
1 2 3 4 4 6 0 0

8
1 2 0 0 4 6 0 0
4


0 1
0 2
ans = 1
*/
