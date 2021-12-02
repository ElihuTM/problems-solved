#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

inline ll n_en_5 ( ll n )
{
	return n * (n-1) * (n-2) * (n-3) * (n-4);
}

int main()
{
	ll n;
	cin >> n;
	
	cout << (n_en_5( n ) / 120 ) * n_en_5( n ) << endl;
	return 0;
}
