//4143
#include <bits/stdc++.h>
#define mod 1000000

using namespace std;

short memos[ 16 ][ 39 ][ 39 ][ 39 ][ 39 ];
char  memoc[ 16 ][ 39 ][ 39 ][ 39 ][ 39 ];
vector<short> comb[ 16 ];
int tedie[ 4 ];
short t1, t2;

inline bool difType( int i, int j) {
	return ((i <= 1)^(j <= 1)) & (( i&1 )^( j&1 ));
}

int Dp(short teds, int a, int b, int c, int d )
{
	if ( a < 0 || b < 0 || c < 0 || d < 0)
		return 0;

	short &heres = memos[ teds ][ a ][ b ][ c ][ d ];
	char  &herec = memoc[ teds ][ a ][ b ][ c ][ d ];
	
	if ( ~heres )
		return (int)heres + ((int)herec * 10000);

	int ans = 0;
	for ( short &t3: comb[ teds ])
		ans += Dp( ((teds&3) << 2) | t3 , a - ( t3 == 0 ), b-( t3 == 1 ), c-( t3 == 2 ), d-( t3 == 3 ) );


	ans %= mod;
	heres = ans % 10000;
	herec = ans / 10000;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio( 0 );
	cin.tie( 0 );

	memset( memos, -1, sizeof memos );
	for (int i = 0; i < 4; ++i)
		cin >> tedie[ i ];

	int n = tedie[ 0 ] + tedie[ 1 ] + tedie[ 2 ] + tedie[ 3 ];
	if( n <= 1 )
		cout << "1\n" ;
	else
	{
		for (short i = 0; i < 4; ++i)
			for (short j = 0; j < 4; ++j)
			{
				memos[ (i << 2) | j ][ 0 ][ 0 ][ 0 ][ 0 ] = 1; memoc[ (i << 2) | j ][ 0 ][ 0 ][ 0 ][ 0 ] = 0;
				for (short k = 0; k < 4; ++k)
					if ( difType( i,j ) || difType( j,k ) || difType( i,k ) )
						comb[ (i << 2) | j ].push_back( k );
			}

		int ans = 0;
		for (short i = 0; i < 4; ++i)
			for (short j = 0; j < 4; ++j)
				ans += Dp( (i << 2) | j, tedie[ 0 ]-(i==0)-(j==0), tedie[ 1 ]-(i==1)-(j==1), tedie[ 2 ]-(i==2)-(j==2), tedie[ 3 ]-(i==3)-(j==3));

		cout << ans % mod << endl;
	}
	return 0;
}
	/*
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
		{
			cout << i << " " << j << ":\n\t";
			for (int c: comb[ i ][ j ] )
				cout << c << " ";
			cout << endl;
		}
	*/

	//cout << sizeof(int)*8 << " " << sizeof(short)*8 << endl;
	//cout << ((1<<31)-1) << " " << ((1<<15)-1) << " " << (1<<7)-1 << endl;
	//cout << INT_MAX << endl;
	//cout << (1^0) << " " << (1^1) << " " << (0^0) << " " << (0^1) << endl;