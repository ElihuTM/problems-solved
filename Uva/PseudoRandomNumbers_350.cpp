#include <bits/stdc++.h>
#define maxn 10003

using namespace std;

int main()
{
	int F[ maxn ];
	int Z, I, M, L, it, caso = 0;
	cin >> Z >> I >> M >> L;
	
	while( Z || I || M || L )
	{
		memset( F, -1, sizeof F );
		it = 0;
		while( F[ L ] == -1 )
		{
			F[ L ] = it;
			++it;
			L = (Z*L + I) % M;
		}
		cout << "Case " << ++caso << ": " << it - F[ L ] << '\n';

		cin >> Z >> I >> M >> L;
	}
	return 0;
}
