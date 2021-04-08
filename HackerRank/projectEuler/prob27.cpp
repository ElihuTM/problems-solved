#include <bits/stdc++.h>
#define maxn 30050000

using namespace std;

bitset <maxn> criba;

void llena()
{
    criba.set();
    criba[ 0 ] = criba[ 1 ] = false;

    for( int i = 4; i < maxn; i += 2 )
        criba[ i ] = false;

    for( long long i = 3; i < maxn; i += 2 )
        if( criba[ i ] )
            for( long long j = i*i; j < maxn; j += i )
                criba[ j ] = false;
}

int ev( int a, int b, int n ) {
    return (n*n + a*n + b > 0 ? n*n + a*n + b : 0);
}

int fun( int a, int b, int n )
{
    for( int i = 1; i <= maxn; ++i )
        if( !criba[ ev(a,b,i) ] )
            return i-1;

    return 0;
}

int main()
{
    int n, aux, ans = -1;
    pair <int, int> res;
    llena();

    cin >> n;
    for( int a = -n; a <= n; ++a )
        for( int b = -n; b <= n; ++b )
        {
            aux = fun( a, b, n );
            if( aux >= ans )
            {
                ans = aux;
                res = make_pair( a, b );
            }
        }
	cout << ans << endl;
    cout << res.first << " " << res.second << '\n';
    return 0;
}
