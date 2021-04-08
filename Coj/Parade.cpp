//4146
#include <iostream>
#include <cstring>
#include <vector>
#define maxn 200003

using namespace std;

vector<int> Lista[ maxn ];
bool visit[ maxn ];
int n, maxSubarbol;

int Dp( int nodo )
{	
	//cout << "entra en " << nodo << endl;
	visit[ nodo ] = true;
	if ( Lista[ nodo ].size() == 1 )
		return 0;
		
	int hijo, padre, pos;
	if ( Lista[ nodo ].size() == 2)
	{
		pos = visit[ Lista[ nodo ][ 0 ] ] ? 0 : 1;
		padre = Lista[ nodo ][ pos ];
		hijo = Lista[ nodo ][ 1-pos ];

		if ( Lista[ hijo ].size() == 2 and padre != 1)
		{
			//cout << "unir :" << padre << " con " << hijo << endl;
			pos = (Lista[ hijo ][ 0 ] == nodo? 0 : 1);
			Lista[ padre ].push_back( hijo );
			Lista[ hijo ][ pos ] = padre;
			return 0;
		}
	}

	int m1 = 0, m2 = 0;
	int aux, ans = Lista[ nodo ].size()-1, aux_subarbol;
	int hermanos = Lista[ nodo ].size()-2;

	for ( int i = 0; i < Lista[ nodo ].size(); ++i)
	{
		int &c = Lista[ nodo ][ i ];
		if( !visit[ c ] )
		{
			aux = Dp( c );
			if ( aux >= m1 )
			{
				m2 = m1;
				m1 = aux;
			}
			else if ( aux > m2)
				m2 = aux;
		}
	}
	ans = max( ans, m1 + hermanos );
	aux_subarbol = max( m1 + m2 + hermanos, m1 + hermanos + 1 );
	maxSubarbol = max( maxSubarbol, aux_subarbol );
	
	//cout << "nodo " << nodo << ": ans = " << ans << " , aux subarbol :  =  " << aux_subarbol << endl;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	int a, b;
	cin >> n;

	maxSubarbol = 0;
	memset(visit, 0, sizeof visit );

	for (int i = 0; i < n-1; ++i)
	{
		cin >> a >> b;
		Lista[ a ].push_back( b );
		Lista[ b ].push_back( a );
	}

	if ( n <= 2)
		cout << "0\n";
	else
	{
		visit[ 1 ] = true;

		int m1 = 0, m2 = 0;
		int aux, ans = 0, aux_subarbol;
		int hermanos = Lista[ 1 ].size()-1;

		for ( int i = 0; i < Lista[ 1 ].size(); ++i)
		{
			int &c = Lista[ 1 ][ i ];
			aux = Dp( c );
			if ( aux >= m1 )
			{
				m2 = m1;
				m1 = aux;
			}
			else if ( aux > m2)
				m2 = aux;
		}

		ans = max( ans, m1 + hermanos );
		aux_subarbol = max( m1 + m2 + hermanos-1, m1 + hermanos );
		maxSubarbol = max( maxSubarbol, aux_subarbol );
		cout << ( ans > maxSubarbol ? ans : maxSubarbol ) << endl;
	}
	return 0;
}