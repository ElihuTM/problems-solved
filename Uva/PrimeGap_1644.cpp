#include <iostream>
#include <bitset>

#define maxn 1299710
#define maxp 10005

typedef long long ll;

class UnionFind {
	int parent[maxn];
	int size[maxn];

public:	
	UnionFind() {
		for(int i=0; i<maxn; ++i) {
			parent[i] = i;
			size[i] = 1;
		}
	}

	int getParent(int a) {
		return (a == parent[a] ? a : parent[a] = getParent(parent[a]));
	}

	void merge(int a, int b) {
		int a_parent = getParent(a);
		int b_parent = getParent(b);

		if(rand() & 1){
			parent[a_parent] = b_parent;
			size[b_parent] += size[a_parent];
		} else {
			parent[b_parent] = a_parent;
			size[a_parent] += size[b_parent];
		}
	}

	int getSize(int a) {
		return size[getParent(a)] + 1;
	}
};

std::bitset<maxn> isPrime;
UnionFind unionFind;

void fillData() {
	// Cribe
	{
		isPrime.set();

		isPrime[0] = isPrime[1] = false;
		for(int i=4; i<maxn; i+=2)
			isPrime[i] = false;

		for(ll i = 3; i<maxn; i+=2)
			if(isPrime[i])
				for(ll j = i*i; j<maxn; j+=i)
					isPrime[j] = false;
	}
	
	// Union find
	{
		for(int i = 2; i<maxn-1; ++i) {
			if(isPrime[i])
				continue;

			if(!isPrime[i+1])
				unionFind.merge(i, i+1);
		}
	}
}


int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	fillData();
	int n;

	do{
		std::cin >> n;
		if(n) {
			if(isPrime[n])
				std::cout << "0\n";
			else
				std::cout << unionFind.getSize(n) << std::endl;
		}
	}while(n);

	return 0;
}

