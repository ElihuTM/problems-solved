#include <iostream>
#include <vector>
#define l(p) (p << 1)
#define r(p) ((p << 1) + 1)
#define mid(a, b) ((a + b) >> 1)

using namespace std;

class SegmentTree {
private:
  string pirates;
  vector<int> tree;
  vector<int> pending_changes;
  int n;

  void build(int p, int i, int j) {
    if (i == j) {
      tree[p] = (pirates[i] == '1');
      return;
    }

    build(l(p), i, mid(i, j));
    build(r(p), mid(i, j) + 1, j);

    tree[p] = tree[l(p)] + tree[r(p)];
  }

  int swap_pending_changes(int changes) {
    if (changes == -1 || changes == 2)
      return changes == 2 ? -1 : 2;

    return 1 - changes;
  }

  void propagate(int p, int i, int j) {
    if (pending_changes[p] == -1)
      return;

    if (pending_changes[p] == 2) {
      tree[p] = (j - i + 1) - tree[p];
      if (i != j) {
        pending_changes[l(p)] = swap_pending_changes(pending_changes[l(p)]);
        pending_changes[r(p)] = swap_pending_changes(pending_changes[r(p)]);
      }
    } else {
      tree[p] = (j - i + 1) * pending_changes[p];
      if (i != j) {
        pending_changes[l(p)] = pending_changes[p];
        pending_changes[r(p)] = pending_changes[p];
      }
    }
    pending_changes[p] = -1;
  }

  void update(int p, int i, int j, int a, int b, int option) {
    propagate(p, i, j);
    if (j < a || i > b) {
      return;
    }

    if (i >= a && j <= b) {
      pending_changes[p] = option;
      propagate(p, i, j);
      return;
    }

    update(l(p), i, mid(i, j), a, b, option);
    update(r(p), mid(i, j) + 1, j, a, b, option);

    tree[p] = tree[l(p)] + tree[r(p)];
  }

  int query(int p, int i, int j, int a, int b) {
    if (j < a || i > b) {
      return 0;
    }

    propagate(p, i, j);
    if (i >= a && j <= b) {
      return tree[p];
    }

    return query(l(p), i, mid(i, j), a, b) +
           query(r(p), mid(i, j) + 1, j, a, b);
  }

public:
  SegmentTree(string &_pirates) {
    pirates = _pirates;
    n = pirates.size();
    tree.assign(6 * n, 0);
    pending_changes.assign(6 * n, -1);

    build(1, 0, n - 1);
  }

  void update(int a, int b, int option) { update(1, 0, n - 1, a, b, option); }
  int query(int a, int b) { return query(1, 0, n - 1, a, b); }
};

int main() {
  int t;
  cin >> t;

  for (int current_case = 1; current_case <= t; ++current_case) {
    cout << "Case " << current_case << ":" << endl;
    int substrings, reps;
    string substr;
    string pirates = "";

    cin >> substrings;
    while (substrings--) {
      cin >> reps;
      cin >> substr;

      while (reps--)
        pirates += substr;
    }

    SegmentTree st(pirates);
    int queries, count = 1;
    cin >> queries;

    while (queries--) {
      char option;
      int a, b;
      cin >> option >> a >> b;

      if (option == 'F')
        st.update(a, b, 1);
      else if (option == 'E')
        st.update(a, b, 0);
      else if (option == 'I')
        st.update(a, b, 2);
      else {
        cout << "Q" << (count++) << ": " << st.query(a, b) << endl;
      }
    }
  }
  return 0;
}