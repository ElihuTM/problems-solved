#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	vector<int> arr;

	cin >> n;
	while( n )
	{
		arr.resize( n );

		cin >> arr[ 0 ];
		while( arr[ 0 ] )
		{
			bool is_pos = true;
			for (int i = 1; i < n; ++i)
				cin >> arr[ i ];
			
			stack <int> s;
			int pos = 1;
			for (int i = 0; i < n && is_pos; ++i)
			{
				while( pos <= arr[ i ] )
				{
					s.push( pos );
					++pos;
				}

				if ( s.top() == arr[ i ] )
					s.pop();
				else
				{
					is_pos = false;
					break;
				}
			}

			if ( is_pos )
				cout << "Yes\n"	;
			else
				cout << "No\n";
			cin >> arr[ 0 ];	
		}
		cout << '\n';
		cin >> n;
	}
	return 0;
}