#include <iostream>
#include <vector>
#include <algorithm>

#define left(n) (n<<1)
#define right(n) ((n<<1)+1)
#define mid(i,j) ((i+j)>>1)
#define maxn 600005
#define inf -100005

using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> node;

const pii invalid(inf, inf);

class SegmentTree {
private:	
	vector<node> tree;
	vector<int> arr;
	int n;
	
	void imp(int p, int i, int j) {
		cout << "\t" << p << " - [" << i << "," << j << "] :";
		for(pii t: tree[p])
			cout << " {" << t.first << "," << t.second << "}";
		cout << endl;
	}

	node merge(node l, node r) {
		if(l.empty() || r.empty())
			return (l.empty()? r : l);

		if(l.back().second == r.front().second) {
			r.front().first += l.back().first;
			l.pop_back();
		}

		node aux;
		copy(l.begin(), l.end(), back_inserter(aux));
		copy(r.begin(), r.end(), back_inserter(aux));
	
		if(aux.size() > 3) {
			pii left = aux.front();
			pii middle = invalid;
			pii right = aux.back();

			for(int i=1; i<aux.size()-1; ++i) {
				middle = max(middle, aux[i]);
			}
			return {left, middle, right};
		}
		
		return aux;
	}

	node query(int p, int i, int j, int a, int b) {
		if(b < i || j < a)
			return node();

		if(a <= i && j <= b) {
			return tree[p];
		}

		const node l = query(left(p), i, mid(i,j), a, b);
		const node r = query(right(p), mid(i,j)+1, j, a, b);

		return merge(l, r);
	}

	void build(int p, int i, int j) {
		if(i == j) {
			tree[p] = {{1, arr[i]}};
			return;
		}

		build(left(p), i, mid(i,j));
		build(right(p), mid(i,j)+1, j);

		tree[p] = merge(tree[left(p)], tree[right(p)]);
	}

public:
	SegmentTree() {
		tree.resize(maxn);
	}

	int query(int a, int b) {
		node q = query(1, 0, n-1, a-1, b-1);
		return max_element(q.begin(), q.end())->first;
	}

	void build(const vector<int>& arr) {
		this->arr = arr;
		n = arr.size();
		build(1, 0, n-1);
	}
};

int main() {
	int n, q, a, b;
	SegmentTree segment;

	cin >> n;
	while(n) {
		cin >> q;
	
		vector<int> arr(n);
		for(int i=0; i<n; ++i)
			cin >> arr[i];
		
		segment.build(arr);
		while(q--) {
			cin >> a >> b;
			cout << segment.query(a, b) << endl;
		}
		cin >> n;
	}
}
