#include <iostream>
#include <cstring>
#include <vector>
#define maxn 200003

using namespace std;


int main()
{
	int n;
	cin >> n;
	int ans = 0;

	for (int i = 2; i <= n ; i += 2)
	{
		ans += (i/2)-1;
	}

	cout << ans << endl;
}