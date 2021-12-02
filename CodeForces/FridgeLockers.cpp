#include <bits/stdc++.h>
#define maxn 1007

using namespace std;

int arr[ maxn ];

int main()
{
	int t, n ,m;
	int min1,pos1, min2,pos2;
	long long sum;
	cin >> t;
	while( t-- )
	{
		cin >> n >> m;
		min1 = min2 = 999999999; sum = 0;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[ i ];
			sum += arr[ i ]*2;
			if ( arr[ i ] <= min1 )
			{
				min2 = min1;
				pos2 = pos1;
				min1 = arr[ i ];
				pos1 = i+1;
			}
			else if( arr[ i ] < min2 )
			{
				min2 = arr[ i ];
				pos2 = i+1; 
			}
		}

		if( m < n || n == 2 )
			cout << "-1\n";
		else
			if( m == n )
			{
				cout << sum << '\n';
				
				cout << "1 " << n << '\n';
				for (int i = 0; i < n-1; ++i)
					cout << i+1 << " " << i+2 << '\n';
			}
		else if( m < 2*(n-2)+1 )
		{
			cout << sum + (m-n)*(min1+min2) << '\n';
			for (int i = 1; i < n-(m-n) ; ++i)
				cout << i << " " << i+1 << '\n';
			
			cout << n-(m-n) << " " << pos1 << '\n';

			for (int i = n-(m-n)+1; i <= n; ++i)
			{
				cout << i << " " << pos1 << '\n';
				cout << i << " " << pos2 << '\n';
			}
		}
		else
		{
			cout << sum + (m-n)*(min1+min2) << '\n';

			for (int i = 1; i <= n ; ++i)
			{
				if( i == pos1 || i == pos2 )
					continue;

				cout << i << " " << pos1 << '\n';
				cout << i << " " << pos2 << '\n';
			}

			for (int i = 2*(n-2)+1; i <= m; ++i)
				cout << pos1 << " " << pos2 << '\n';
		}
	}
	return 0;	
}