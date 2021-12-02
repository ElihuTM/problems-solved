#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

bool arr[ maxn ];

int main()
{
	memset( arr, 0, sizeof arr );
	queue <int> ent;
	queue <int> sal;

	int n, a;
	cin >> n;
	for( int i = 0; i < n; ++i)
	{
		cin >> a;
		ent.push( a );
	}
	for( int i = 0; i < n; ++i)
	{
		cin >> a;
		sal.push( a );
	}

	int ans = 0;
	while( !sal.empty() )
	{
		if( arr[ ent.front() ] )
		{
			ent.pop();
			continue;
		}

		if( sal.front() == ent.front() )
		{
			sal.pop();
			ent.pop();
		}
		else
		{
			arr[ sal.front() ] = true;
			sal.pop();
			++ans;
		}
	}
	cout << ans << '\n';
	return 0;
}
