#include <iostream>
#include <vector>
#include <sstream>

#define left(n) (n<<1)
#define right(n) ((n<<1)+1)
#define mid(i,j) ((i+j)>>1)
#define inf 100005

using namespace std;
typedef vector<int> vi;

class SegmentTree {
private:
	vi arr;
	vi tree;
	int n;
	
	//void imp (int p, int i, int j) {
		//printf("\t%d - [%d, %d] : %d\n", p, i, j, tree[p]);
	//}

	int query(int p, int i, int j, int a, int b) {
		if(b < i || j < a)
			return -1;

		if(a <= i && j <= b)
			return tree[p];

		int l = query(left(p), i, mid(i,j), a, b);
		int r = query(right(p), mid(i,j)+1, j, a, b);

		if(l == -1 || r == -1)
			return (l == -1 ? r : l);

		return (arr[l] < arr[r] ? l : r);
	}

	void update(int p, int i, int j, int a, int value) {
		if(a < i || j < a)
			return;

		if(a == i && j == a) {
			arr[i] = value;
			tree[p] = i;
			return;
		}
		
		update(left(p), i, mid(i,j), a, value);
		update(right(p), mid(i,j)+1, j, a, value);

		tree[p] = (arr[tree[left(p)]] < arr[tree[right(p)]] ? tree[left(p)] : tree[right(p)]);
	}

public:
	SegmentTree(int size) {
		n = size;
		arr.assign(n, inf);
		tree.assign(6*n, 0);
	}

	void update(int position, int value) {
		update(1, 0, n-1, position - 1, value);
	}

	void update(vi& positions) {
		int aux = arr[positions.front()];
		int len = positions.size();

		for(int i=0; i<len-1; ++i)
			update(positions[i] + 1, arr[positions[i+1]]);
		update(positions.back() + 1, aux);
	}

	int query(int a, int b) {
		return arr[query(1, 0, n-1, a, b)];
	}

	//void imp() {
		//cout << "-- ";
		//for(int i: arr)
			//cout << i << " ";
		//cout << "--\n";
	//}
};

vi getValues(string aux) {
	for(char& letter: aux)
		if(letter == ',')
			letter = ' ';

	int a;
	vi values;
	stringstream ss(aux);

	while(ss >> a)
		values.push_back(a-1);

	return values;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, q, a;
	string query;

	cin >> n >> q;
	
	SegmentTree segment(n);
	for(int i=1; i<=n; ++i) {
		cin >> a;
		segment.update(i, a);
	}

	while(q--) {
		cin >> query;
		
		vi values = getValues(query.substr(6, query.size() - 7));
		if(query[0] == 'q') {
			cout << segment.query(values[0], values[1]) << endl;
		} else {
			segment.update(values);
		}
	}
	return 0;
}
