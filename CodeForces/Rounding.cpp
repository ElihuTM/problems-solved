#include <bits/stdc++.h>
#define minimum first
#define maximum second
#define mod 1000000007
#define maxn 100005
#define md(x) (((x%mod) + mod) % mod)
#define p_b(a) push_back(a)
#define all(x) x.begin(),x.end()
#define sz(a) s.size()
#define endl '\n'
 
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector <ll> vi;
typedef vector <vi> vvi;
typedef pair <ll,ll> pii;
typedef vector <pii> vpii;
 
struct place {
	string name;
	int percent;
 
	place ( ) { }
	place ( string name, int percent ) {
		this->name = name;
		this->percent = percent;
	}
};
 
const pair< int, int> IMPOSSIBLE( -1, -1 );
const int negative = -50;
const int positive = 49;
const int a_decimal = 1;
 
vector<place> places;
int number_of_places,
	positive_numbers;
 
void read_input( int &percentages_sum ) {
	percentages_sum = 0;
	positive_numbers = 0;

	int percent;
	string name;
 
	cin >> number_of_places;
 
	places.resize( number_of_places );
	for (int i = 0; i < number_of_places; ++i)
	{
		cin >> name >> percent;
		places[ i ] = place( name, percent*100 );
		percentages_sum += percent*100;

		if( percent > 0 )
			++positive_numbers;
	}
}
 
bool is_in_interval( int percentages_sum ) {
 
	int average = 10000 - percentages_sum;
	
	if (average > 0)
		average = (average + number_of_places - 2) / (number_of_places-1);
 	else {
 		int n = positive_numbers - (positive_numbers != number_of_places);
 		average = (average - n + 1) / (n);
 	}

	if( negative <= average and average <= positive )
		return true;
	
	return false;
}
 
pair <int, int> get_interval( int &percentages_sum ) {
	pair <int, int> answer = IMPOSSIBLE;

	int position = 0;
	while ( places[ position ].percent != 0) ++position;

	percentages_sum -= places[ position ].percent;
 
	int percent;
	const int real_number = places[ position ].percent,
			minimum_possible = real_number - 50,
			maximum_possible = real_number + 49;
 
	percent = maximum_possible;
	while( percent >= minimum_possible ) {
		if( is_in_interval( percent + percentages_sum ) ) {
			answer.maximum = percent - real_number;
			break;
		}
 
		percent -= a_decimal;
	}
	
	percent = minimum_possible;
	while( percent <= maximum_possible ) {
		if (is_in_interval( percent + percentages_sum ) ) {
			answer.minimum = percent - real_number;
			break;
		}
		percent += a_decimal;
	}
	return answer;
}
 
void print_real( int n ) {
	if( n < 0 ) {
		cout << "0.00";
		return;
	}

	cout << n / 100 << '.';
 
	n %= 100;
	if( n < 10 )
		cout << 0;
 
	cout << n;
}
 
int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
 
	int percentages_sum;
	read_input( percentages_sum );
 
	if( number_of_places == 1 or positive_numbers <= 1 ) {
		if( percentages_sum == 10000 )
			for (int i = 0; i < number_of_places; ++i) {
				cout << places[ i ].name << " " << places[ i ].percent/100 << ".00 " << places[ i ].percent/100 << ".00" << endl;
			}
		else
			cout << "IMPOSSIBLE" << endl;
 
		return 0;
	}

	pair <int, int> interval = get_interval( percentages_sum );
	
	if( interval == IMPOSSIBLE )
		cout << "IMPOSSIBLE" << endl;
	else {
		for (int i = 0; i < number_of_places; ++i) {
			int number = places[ i ].percent;
			cout << places[ i ].name << " ";
			print_real( interval.minimum + number );
			cout << " ";
			print_real( interval.maximum + number );
			cout << endl;
		}
	}
 
	return 0;
}