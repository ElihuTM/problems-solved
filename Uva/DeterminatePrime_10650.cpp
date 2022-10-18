#include <iostream>
#include <vector>
#include <bitset>

#define maxn 32005

using namespace std;

bitset<maxn> isPrime;
vector<int> primes;
vector<vector<int>> determinatePrimes;

void fillData() {
	// fill Primes
	{
		isPrime.set();
		isPrime[0] = isPrime[1] = false;
	
		for(long long i = 2; i<maxn; ++i)
			if(isPrime[i]) {
				primes.push_back(i);
				for(long long j = i*i; j<maxn; j+=i)
					isPrime[j] = false;
			}
	}

	// fill Determinate Primes
	{
		for(int prime: primes) {
			for(int i=1; i<maxn; ++i) {
				int a = prime + i;
				int b = a + i;

				if(a >= maxn || b >= maxn)
					break;

				if(isPrime[a] && isPrime[b])
					determinatePrimes.push_back({prime, a, b});
			}
		}
	}
}

int main() {

	fillData();	

	cout << determinatePrimes.size() << endl;
	for(vector<int> determinatePrime: determinatePrimes) {
		cout << "{";
		for(int prime: determinatePrime) {
			cout << ' ' << prime;
		}
		cout << "}\n";
	}
	return 0;
}
