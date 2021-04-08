#include <iostream>
#include <cstring>
#define maxn 201
#define end '\n'

using namespace std;
typedef long long ll;

ll memo[ maxn ][ maxn ][ maxn ];
int suma, modulo, querys, digitos;

ll Dp( int pos, int n, int residuo )
{
	if ( n < 0 )
		return 0;

	if ( !pos )
		return ( !n && !residuo );

	if ( ~memo[ pos ][ n ][ residuo ] )
		return memo[ pos ][ n ][ residuo ];

	ll ans = 0;
	for (int i = (pos == digitos); i < 10; ++i)
		ans += Dp( pos-1, n-i, ((residuo*10)+i) % modulo );

	return memo[ pos ][ n ][ residuo ] = ans;
}

bool is( int n )
{
	if( n % modulo )
		return false;

	int tot = 0;
	while( n )
	{
		tot += (n%10);
		n /= 10;
	}
	return ( tot == suma);
}

int main()
{
	cin >> suma >> modulo >> querys;
	memset(memo, -1, sizeof memo );

	for (int i = 10; i > 0; --i)
	{
		digitos = i;
		cout << Dp( i, suma , 0) << endl;
	}
	
	for (int i = 10; i > 0 ; --i)
	{
		cout << i << " Digitos :\n";
		for (int j = 0; j < 10 ; ++j)
		{
			for (int k = 0; k < 200; ++k)
			{
				if ( ~memo[ i ][ j ][ k ] )
				{
					cout << "\t{ " << i <<" , " << j << " , " << k <<"} : " << memo[ i ][ j ][ k ] << endl;
				}
			}
		}
		cout << endl;
	}

	cout << endl << endl;

	int cont = 0;
	for (int i = 1; i < 10000; ++i)
	{
		if( is( i ) )
		{
			cont++;
			if( cont == 2)
				cout << i << endl;
		}
	}

	return 0;
}