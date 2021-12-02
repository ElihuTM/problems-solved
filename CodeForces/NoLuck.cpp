#include <bits/stdc++.h>
#define endl '\n'
#define MAX_X 300003

using namespace std;

class Query {
public:
	int value, a, b, real_position, ans;

	bool operator <(const Query& p) const {
		return value >= p.value;
	}	
};

class FenwickTree {
private:
	vector<int> ft;
	int size;

	int LSOne(const int &x) {
		return x&(-x);
	}
public:
	FenwickTree(int x): size(x), ft(vector<int>(x)) {}
	int query (int a) {
		int sum = 0;
		for(int i=a; i>0; i-=LSOne(i))
			sum += ft[i];
		return sum;
	}

	int query (int a, int b) {
		return query(b) - query(a);
	}

	void update (const int& position, const int& value = 1) {
		for(int i=position; i<size; i+=LSOne(i))
			ft[i] += value;
	}

	void update(const vector<int> &positions, const int& value = 1) {
		for(const int& position: positions)
			update(position, value);
	}
};

bool orderByRealPosition(const Query &a, const Query &b) {
	return a.real_position < b.real_position;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n);
	vector<Query> querys(m);
	vector<vector<int>> reps(MAX_X);
	FenwickTree fenwickTree(MAX_X);

	for(int i=0; i<n; ++i) {
		cin >> arr[i];
		reps[arr[i]].push_back(i+1);
	}
	for(int i=0; i<m; ++i) {
		cin >> querys[i].a >> querys[i].value >> querys[i].b;
		querys[i].real_position = i;
	}
	sort(querys.begin(), querys.end());

	int current_value = MAX_X;
	for(Query& query: querys) {
		while(current_value >= query.value) {
			fenwickTree.update(reps[current_value]);
			--current_value;
		}

		query.ans = (arr[query.a-1] >= query.value ? 0 : fenwickTree.query(query.a, query.a + query.b));
	}

	sort(querys.begin(), querys.end(), orderByRealPosition);
	for(const Query& query: querys)
		cout << query.ans << endl;
	return 0;
}
