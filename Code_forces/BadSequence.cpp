#include <bits/stdc++.h>

using namespace std;

int main()
{
	
	int n;
	cin >> n;
	string cad, ans;
	
	cin >> cad;
	for( int i = 0; i < n; ++i )
	{
		if( cad[ i ] == ')' )
		{
			if( ans.empty() || ans.back() == ')' )
				ans.push_back( ')' );
			else
				ans.pop_back();
		}
		else
			ans.push_back( '(' );
	}
	
	if( ans == "" || ans == ")(" || ans == "()" )
		cout << "Yes\n";
	else
		cout << "No\n";	
	return 0;
}
