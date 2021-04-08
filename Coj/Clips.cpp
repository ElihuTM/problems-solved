//4156
#include <iostream>
#define maxn 5000003

using namespace std;

bool arr[ maxn ];

int main()
{
	bool is_pos = true;
	string cad;
	int n, len;

	cin >> n;
	cin >> cad;

	if( n&1 )
		cout << n-1 << endl;
	else
	{
		len = cad.size();
		for (int i = 0; i < len; i+=2)
			arr[ i/2 ] = ( cad[ i ] == 'A' || cad[ i ] == 'C');
		
		for (int i = 0; i < n; i+=2)
			if ( !arr[ i ] || arr[ i+1 ] )
			{
				is_pos = false;
				break;
			}

		if ( is_pos )
			cout << n << endl;
		else
			cout << n-1 << endl;

	}
	return 0;
}