#include <iostream>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef long double ld;

int main()
{
	ll L, H;

	cin >> H >> L;
	
	cout << fixed;
	cout << setprecision(8) << (ld)(L*L - H*H) / (ld)(H+H) << '\n'; 
	return 0;
}