#include <iostream>

using namespace std;

int abs( int n){
	return n > 0 ? n : -n;
}

int main()
{
	int n; 
	cin >> n;
	if ( n <= 0)
		cout << 1-abs(n*(n-1)/2) << endl;
	else
		cout << n*(n+1)/2 << endl;
	return 0;
}