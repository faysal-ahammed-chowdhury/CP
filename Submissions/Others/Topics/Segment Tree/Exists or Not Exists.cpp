#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N];

struct MST { // merge sort tree
  set<int> tree[4 * N];

  set<int> merge(set<int> &a, set<int> &b) {
    set<int> se;
    for (auto x : a) {
      se.insert(x);
    }
    for (auto x : b) {
      se.insert(x);
    }
    return se;
  }

  void build(int n, int b, int e) {
    if (b == e) {
      set<int> se;
      se.insert(a[b]);
      tree[n] = se;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }

  int query(int n, int b, int e, int i, int j, int x) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) {
      bool found = tree[n].find(x) != tree[n].end();
      return found;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j, x);
    int R = query(r, mid + 1, e, i, j, x);
    return (L | R);
  }
} mst;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  mst.build(1, 1, n);
  while (q--) {
    int i, j, x; cin >> i >> j >> x;
    if (mst.query(1, 1, n, i, j, x)) cout << "YES\n";
    else cout << "NO\n";
  }

  return 0;
}
