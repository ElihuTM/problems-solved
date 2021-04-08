#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector <string> terms;
vector <string> die;
vector <string> asd;
vector <string> unid;

string gen( int n )
{
	string ans = "";
	if( n/100 != 0 )
	{
		ans += unid[ n/100 ] + " Hundred";
		if( n%100 != 0 )
			ans += " ";
	}

	n = n%100;
	if( n )
	{
		if( n/10 == 0)
			return ans + unid[ n%10 ];

		if( n/10 == 1 )
			return ans + die[ n%10 ];
		
		ans += asd[ n/10 ];
		if( n % 10 != 0)
			ans += " " + unid[ n%10 ];
	}

	return ans;
}

int main()
{
	stack <string> s;

	terms.push_back( "" );
	terms.push_back( "Thousand" );
	terms.push_back( "Million" );
	terms.push_back( "Billion" );
	
	unid.push_back("Zero");
	unid.push_back("One");
	unid.push_back("Two");
	unid.push_back("Three");
	unid.push_back("Four");
	unid.push_back("Five");
	unid.push_back("Six");
	unid.push_back("Seven");
	unid.push_back("Eight");
	unid.push_back("Nine");

	die.push_back("Ten");
	die.push_back("Eleven");
	die.push_back("Twelve");
	die.push_back("Thirteen");
	die.push_back("Fourteen");
	die.push_back("Fifteen");
	die.push_back("Sixteen");
	die.push_back("Seventeen");
	die.push_back("Eighteen");
	die.push_back("Nineteen");
	
	asd.push_back("Zero");
	asd.push_back("Ten");
	asd.push_back("Twenty");
	asd.push_back("Thirty");
	asd.push_back("Forty");
	asd.push_back("Fifty");
	asd.push_back("Sixty");
	asd.push_back("Seventy");
	asd.push_back("Eighty");
	asd.push_back("Ninety");
	
	int t;
	ll x;

	cin >> t;
	while( t-- )
	{
		int it = 0;
		cin >> x;

		if( x == 0 )
			cout << unid[ 0 ] << '\n';
		else if( x == 1000000000000 )
			cout << "One Thousand Billion" << '\n';
		else
		{
			while( x )
			{
				s.push( gen( x%1000 ) );
				x /= 1000;
				++it;
			}
			--it;

			while( !s.empty() )
			{
				cout << s.top();
				if( s.top() != "" )
					cout << " " << terms[ it ] << " ";

				--it;
				s.pop();
			}
			cout << '\n';
		}
	}
	return 0;
}
