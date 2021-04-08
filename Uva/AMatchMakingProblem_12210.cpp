#include <bits/stdc++.h>
#define maxn 65

using namespace std;

//int bach[ maxn ];
//int sprin[ maxn ];

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );
		
	int n,m,a,mini, it = 0;

	cin >> n >> m;
	while( n || m )
	{
		mini = 61;
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			mini = min( mini, a );
		}

		for (int i = 0; i < m; ++i)
		{
			cin >> a;
		}

		cout << "Case " << ++it << ": ";
		if( n <= m )
			cout << "0\n";
		else
			cout << n-m << " " << mini << '\n';

		cin >> n >> m;
	}
	return 0;
}