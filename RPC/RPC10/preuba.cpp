#include <bits/stdc++.h>

using namespace std;

int main()
{
	string cad1 = "123";
	string cad2 = "00000";

	cout << cad1 << "is" << (cad2 < cad1? "less" : "greater") << " than " << cad2 << endl;
	return 0;
}
