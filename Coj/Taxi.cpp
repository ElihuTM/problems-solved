//4166
#include <iostream>
#include <algorithm>
#define maxn  40002

using namespace std;
typedef pair <int,int> pii;

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int Casos,n,x,y;
	cin >> Casos;

	while( Casos-- )
	{
		cin >> n;

		cin >> x >> y;
		pii min1(x,y), min2(x,y), max1(x,y), max2(x,y);

		for (int i = 1; i < n; ++i)
		{
			cin >> x >> y;

			if ( x + y > max1.first+max1.second )
				max1 = make_pair(x,y);
			if ( x + y < min1.first+min1.second )
				min1 = make_pair(x,y);

			if ( x - y > max2.first-max2.second )
				max2 = make_pair(x,y);
			if ( x - y < min2.first-min2.second )
				min2 = make_pair(x,y);
		}

		cout << max( abs(max1.first-min1.first) + abs(max1.second-min1.second),
					abs(max2.first-min2.first) + abs(max2.second-min2.second) ) << endl;
	}	
	return 0;
}