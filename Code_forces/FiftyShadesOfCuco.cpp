#include <bits/stdc++.h>
#define maxn 1000004
using namespace std;
 
typedef complex<double> point;
typedef int ll;

char cad[ maxn ];

void fft( vector<point> &a, int sign = +1)
{
    int n = a.size();
    for (int i = 1, j = 0; i < n - 1; ++i)
    {
        for (int k = n >> 1; (j ^= k) < k; k >>= 1);
        
        if (i < j ) swap(a[i], a[j]);
    }
 
    double theta = 2 * atan2(0, -1) * sign;
 
    for (int m, mh = 1; (m = mh << 1) <= n; mh = m)
    {
        point wm(cos(theta / m), sin(theta / m)), w(1, 0);
 
        for (int i = 0; i < n; i += m, w = point(1, 0))
            for (int j = i, k = j + mh; j < i + mh; ++j, ++k, w = w * wm)
            {
                point x = a[j], y = a[k] * w;
                a[j] = x + y;
                a[k] = x - y;
            }
    }
 
    if (sign == -1)
        for (point &p : a) p = p / (1. * n);
}

int main()
{
    double val;
    char salto;
    ll n, m;

    scanf("%d%d%c", &n, &m, &salto );
    ll tot = 1; while(tot < (n + m)) tot <<= 1;
    vector<point> uno_a( tot );
    vector<point> dos_a( tot );
    
    scanf("%s",cad);
    for(int i = 0; i < n ; ++i )
        uno_a[ i ] = { (cad[i] == 'a' ? 1.0: -1.0), 0.0};

    scanf("%s",cad);
    for(int i = 0; i < m; ++i )
        dos_a[ i ] = { (cad[m-i-1] == 'a' ? 1.0: -1.0), 0.0};
    
    fft(uno_a,1);
    fft(dos_a,1);

    for(int i = 0; i < tot; ++i)
        uno_a[ i ] *= dos_a[ i ]; 
    
    fft(uno_a,-1);

    vector< vector< ll > > answer( m+1 );
    ll posicion = 0;

    for( int i = 0; i <= n-m; ++i )
        answer[ m - ((ll)(round(uno_a[ m+i-1 ].real()) + m)/2) ].push_back( ++posicion );
 
    for (int i = 0; i <= m; ++i)
    {
        printf("%d:", i );
        for (int j = 0; j < answer[ i ].size(); ++j)
            printf(" %d", answer[ i ][ j ] );
        printf("\n");
    }
    
    return 0;
}
