#include <bits/stdc++.h>
#define ep 0.001

using namespace std;

const double PI = acos(-1);

int main()
{
	int l,m,hip,x,y,ang;

	cin >> l >> m >> hip;
	cin >> x >> y >> ang;

	double co = cos(ang*PI/180)*hip;
	double ca = sin(ang*PI/180)*hip;

	if ( x+co >= -ep && x+co <= m+ep && y+ca >= -ep && y+ca <= l+ep )
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}