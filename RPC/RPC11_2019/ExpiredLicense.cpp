#include <bits/stdc++.h>
#define maxn 10000007

using namespace std;
typedef vector <int> vi;

bitset <maxn> criba;
vi p;

void llenar()
{
	criba.set();
	criba[ 0 ] = criba[ 1 ] = 0;
	
	p.push_back( 2 );
	for( int i = 4; i < maxn; i += 2 )
		criba[ i ] = 0;

	for( long long i = 3; i < maxn; i+=2 )
		if( criba[ i ] )
		{
			p.push_back( i );
			for( long long j = i*i; j < maxn; j+=i )
				criba[ j ] = 0;
		}
}

void fact(vi &ans, int n )
{
	int pp = 2;
	int pos = 0;

	while( pp * pp <= n )
	{
		if( n%pp == 0 )
		{
			ans.push_back( pp );
			while( n%pp == 0 )
				n /= pp;
		}
		
		pp = p[ ++pos ];
	}

	if( n != 1 )
		ans.push_back( n );
}

bool pos( vi &_a, int a, vi &_b, int b )
{
	pair <int,int> ans( 0, 0 );
	bool ban = false;

	for( int i = 0; i < _a.size(); ++i )
	{
		for( int j = 0; j < _b.size(); ++j )
		{
			if( a/_a[ i ] == b/_b[ j ] )
			{
				if( !ban )
				{
					ban = true;
					ans = make_pair( _a[i],_b[j] );
				}
				else
					if( ans.first + ans.second > _a[ i ] + _b[ j ] )	
						ans = make_pair( _a[i],_b[j] );
			}
		}
	}
	
	if( ban )
		cout << ans.first << " " << ans.second << '\n';
	
	return ban;
}

int main()
{
	float x, y;
	int a, b;
	int n;

	cin >> n;
	llenar();

	while( n-- )
	{
		cin >> x >> y;
		a = round( x*100000 );
		b = round( y*100000 );
		
		if( a == b )
		{
			cout << "2 2\n";
			continue;
		}
		
		vi _a; fact(_a, a );
		vi _b; fact(_b, b );
			
		if( !pos( _a, a, _b, b) )
			cout << "impossible\n";
	
	}
	return 0;
}
