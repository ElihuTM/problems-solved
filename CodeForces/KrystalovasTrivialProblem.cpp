#include <iostream>
#include <vector>

#define left(p) (p<<1)
#define right(p) ((p<<1)+1)
#define mid(a,b) ((a+b)>>1)
#define MODULE 1000000007LL
#define mod(x) (((x % MODULE) + MODULE) % MODULE)

using namespace std;
typedef long long ll;
 
class SegmentTree {
private:
	vector<ll> square;
	vector<ll> sum;
	vector<ll> updates; 
	int n;
 
	void propagate(int p, int i, int j) {
		const ll len = mod((j-i+1) * updates[p]);
		const ll ab = mod(mod(2 * updates[p]) * sum[p]);
		const ll b2 = mod(len * updates[p]);			  

		sum[p] = mod(sum[p] + len);
		square[p] = mod(mod(square[p] + ab) + b2);
		if(i != j) {
			updates[left(p)] = mod(updates[left(p)] + updates[p]);
			updates[right(p)] = mod(updates[right(p)] + updates[p]);
		}
		updates[p] = 0;
	}
 
	void update(int p, int i, int j, int a, int b, ll value) {
		propagate(p, i, j);
 
		if(b < i || j < a)
			return;
 
		if(a <= i && j <= b) {
			updates[p] = mod(updates[p] + value);
			propagate(p, i, j);
 
			return;
		}
 
		update(left(p), i, mid(i,j), a, b, value);
		update(right(p), mid(i,j)+1, j, a, b, value);
 
		sum[p] = mod(sum[left(p)] + sum[right(p)]);
		square[p] = mod(square[left(p)] + square[right(p)]);
	}
 
	ll query(int p, int i, int j, int a, int b) {
		// printf("\t%d: [%d, %d]\n", p, i ,j);
		propagate(p, i, j);
		if(b < i || j < a)
			return 0; 
 
		if(a <= i && j <= b) {
			return square[p];
		}
 
		ll l = query(left(p), i, mid(i,j), a, b);
		ll r = query(right(p), mid(i,j)+1, j, a, b);
 
		return mod(l + r);
	}
 
public:
	SegmentTree(int size) {
		n = size;
		square.assign(6*n, 0);
		sum.assign(6*n, 0);
		updates.assign(6*n, 0);
	}
 
	void update(int a, int b, int value) {
		update(1, 0, n-1, a-1, b-1, value);
	}
 
	ll query(int a, int b) {
		return query(1, 0, n-1, a-1, b-1);
	}
};
 
 
int main() {
	int n, q;
	int a, b, c;
	char op;
	cin >> n >> q;
 
	SegmentTree segment(n);
	for(int i=1; i<=n; ++i) {
		cin >> a;
		segment.update(i, i, a);
	}
 
	while(q--) {
		cin >> op;
		if(op == 'u') {
			cin >> a >> b >> c;
			segment.update(a, b, c);
		} else {
			cin >> a >> b;
			cout << segment.query(a, b) << endl;
		}
	}

	return 0;
}

