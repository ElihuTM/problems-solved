#include <iostream>
#include <vector>
#define maxn 1000000007

using namespace std;

vector<int> S;

int lower_bound( int i, int j, int valor )
{
	int m;
	while( j-i > 1)
	{
		m = i + (j-i)/2;
		if (S[ m ] >= valor)
			j = m;
		else
			i = m;
	}
	return j;
}

char Dp(int n, int pos)
{
	if ( n > S[ pos-1 ] and n < S[ pos ] - S[ pos-1 ])
		return n == S[ pos-1 ] + 1 ? 'm' : 'o';

	return n <= S[ pos-1 ] ? Dp( n, pos-1) : Dp( n - (S[ pos-1 ] + pos + 3 ), pos-1 );
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, it = 1;

	cin >> n;
	S.push_back( 3 );
	while( S.back() < maxn )
	{
		S.push_back( 2*S.back() + it + 3);
		it++;
	}

	int pos;
	pos = lower_bound( -1, S.size()-1, n);
	cout << Dp( n, pos) << endl;
	return 0;
}