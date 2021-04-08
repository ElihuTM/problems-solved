#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

long long arr[ maxn ];
int n, c, t;

bool is_pos( long long k )
{
	int cont = 0, sum = 0;
	for( int i = 0; i < n; ++i )
	{
		if( sum + arr[ i ] > k*t )
		{
			++cont;
			sum = arr[ i ];
		}
		else
			sum += arr[ i ];
	}
	++cont;

	return cont <= c;
}

int l_b( int i, int j )
{
	int m;
	while( j-i > 1 )
	{
		m = i + (j-i)/2;
		if( is_pos( m ) )
		{
			//cout << "with " << m << " is possible\n";
			j = m;
		}
		else
		{
			//cout << "with " << m << " is not possible\n";
			i = m;
		}
	}

	return j;
}

 int main()
{
	cin >> n >> c >> t;
	long long maxi = 0;

	for( int i = 0; i < n; ++i )
	{
		cin >> arr[ i ];
		maxi = max( maxi, arr[ i ] );
	}

	cout << l_b( ceil( (double)maxi / (double)t ) - 1 , 1000000007 ) << '\n';
	return 0;
}
