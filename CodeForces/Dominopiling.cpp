#include <bits/stdc++.h>
#define sum(n,m) (n/2)*m+(m/2)

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	if( !(n&1) )
		cout << (n/2) * m << endl; 
	else
	{
		if( !(m&1) )
			cout << (m/2) * n << endl;
		else
			cout << max( sum(n,m) , sum(m,n)) << endl;
	}
	return 0;
}
