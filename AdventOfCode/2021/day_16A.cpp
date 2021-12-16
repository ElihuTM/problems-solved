#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string bin;
int n;

class Package {
public:
	int version;
	int id;
	int endAt;
	ll value;
	vector<Package*> subPackages;

	Package(int inicio = 0, int fin = n) {
		version = toInt(bin.substr(inicio, 3));
		id = toInt(bin.substr(inicio+3, 3));

		if(id == 4)
			tie(value, endAt) = getLiteralValue(inicio + 6, fin);
		else
			tie(subPackages, endAt) = getSubpackages(inicio + 6, fin);
	}

	ll toInt(const string& c) {
		ll ans = 0;
		for(char bit: c)
			ans = (ans*2) + bit - '0';
		return ans;
	}

	pair<ll,int> getLiteralValue(int i, int fin) {
		string ans;	
		for(; bin[i] != '0'; i+=5)
			ans += bin.substr(i+1, 4); 

		ans += bin.substr(i+1, 4);
		return {toInt(ans), i+5};
	}

	pair<vector<Package*>,int> getSubpackages(int inicio, int fin) {
		vector<Package*> sub;
		Package* aux;

		if(bin[inicio] == '0') {
			int len = toInt(bin.substr(inicio + 1, 15));
			inicio += 16;
			fin = inicio + len;
			while(inicio < fin) {
				aux = new Package(inicio, fin);
				sub.push_back(aux);
				inicio = aux->endAt;
			}
		} else {
			int len = toInt(bin.substr(inicio + 1, 11));
			inicio += 12;
			for(int i=0; i<len; ++i) {
				aux = new Package(inicio, fin);
				sub.push_back(aux);
				inicio = aux->endAt;	
			}
			fin = inicio;
		}
		return {sub, fin};
	}

	int getSumOfVersions() {
		int ans = version;
		for(Package* package: subPackages) {
			ans += package->getSumOfVersions();
		}
		return ans;
	}

	ll getSumOfPackages() {
		ll ans;
		switch (id) {
			case 4:
				ans = value;
				break;
			case 0:
				ans = 0;
				for(Package* package: subPackages)
					ans += package->getSumOfPackages();
				break;
			case 1:
				ans = 1;
				for(Package* package: subPackages)
					ans *= package->getSumOfPackages();
				break;
			case 2:
				ans = subPackages.front()->getSumOfPackages();
				for(Package* package: subPackages)
					ans = min(ans, package->getSumOfPackages());
				break;
			case 3:
				ans = subPackages.front()->getSumOfPackages();
				for(Package* package: subPackages)
					ans = max(ans, package->getSumOfPackages());
				break;
			case 5:
				ans = (subPackages[0]->getSumOfPackages() > subPackages[1]->getSumOfPackages());
				break;
			case 6:
				ans = (subPackages[0]->getSumOfPackages() < subPackages[1]->getSumOfPackages());
				break;
			case 7:
				ans = (subPackages[0]->getSumOfPackages() == subPackages[1]->getSumOfPackages());
				break;
		}
		return ans;
	}
};

void getInput() {
	string cad;
	map<char, string> dict = {
		{'0', "0000"}, {'1', "0001"}, {'2', "0010"}, {'3', "0011"},
		{'4', "0100"}, {'5', "0101"}, {'6', "0110"}, {'7', "0111"},
		{'8', "1000"}, {'9', "1001"}, {'A', "1010"}, {'B', "1011"},
		{'C', "1100"}, {'D', "1101"}, {'E', "1110"}, {'F', "1111"},
	};
	cin >> cad;
	for(char letter: cad)
		bin += dict[letter];
	n = bin.size();
}

int main() {
	getInput();
	Package* ans = new Package();

	cout << ans->getSumOfVersions() << endl;
	cout << ans->getSumOfPackages() << endl;
	return 0;
}
