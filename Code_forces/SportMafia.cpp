#include <iostream>

using namespace std;
typedef long long ll;

int n, k;

ll sum( ll n )
{
	return (n*(n+1))/2;
}

ll u_p( int i, int j )
{
	if( n == 1 )
		return 0;

	if( sum(n) == k )
		return 0;
	
	int m;
	while( j >= i )
	{
		m = i + (j-i)/2;
		if( sum(m)-(n-m) == k )
			return n-m;
		else if( sum(m)-(n-m) < k )
			i = m+1;
		else
			j = m-1;
	}

	return n-j;
}

int main()
{
	cin >> n >> k;

	cout << u_p( 0, n ) << endl;
	
	return 0;
}
