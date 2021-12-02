#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;
typedef long long ll;

ll fast_pow( ll value, ll exp )
{
	ll answer = 1;
	while( exp )
	{
		if ( exp&1 )
			answer = (answer * value) % mod;

		value = (value * value ) % mod;
		exp >>= 1;
	}

	return answer;
}

inline ll gauss( ll n ) {
	return n * (n+1) / 2;
}

void input( vector<ll> &reps_of_prime, vector<ll> &mult_factors )
{
	ll num_of_primes, prime, exp;
	map <ll,ll> exp_of_primes;

	cin >> num_of_primes;
	for(int i=0; i < num_of_primes; ++i )
	{
		cin >> prime;
		exp_of_primes[ prime ]++;
	}

	for ( auto c: exp_of_primes )
	{
		prime = c.first;
		exp = c.second;

		reps_of_prime.push_back( exp );
		mult_factors.push_back( fast_pow( prime, gauss(exp) ) );
	}
}

int main()
{
	vector<ll> reps_of_prime;
	vector<ll> mult_factors;
	ll prime, exp;

	input( reps_of_prime, mult_factors );

	for (int i = mult_factors.size()-2; i >= 0 ; --i)
	{
		ll auxiliar1 = fast_pow( mult_factors[ i+1 ], reps_of_prime[ i ] + 1 );
		ll auxiliar2 = fast_pow( mult_factors[ i ], reps_of_prime[ i+1] + 1 );
		mult_factors[ i ] = (auxiliar1 * auxiliar2 ) % mod;
	}

	cout << mult_factors[ 0 ] % mod << endl;
	return 0;
}