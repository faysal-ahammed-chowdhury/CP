#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 3e5 + 9;
int n, a[N];

struct node {
  int val, idx;
};

node merge(node &l, node &r) {
  node ans;
  ans.val = l.val ^ r.val;
  if (l.val >= r.val) ans.idx = l.idx;
  else ans.idx = r.idx;
  return ans;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {a[b], b};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = {x, b};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int idx) {
    if (tree[n].idx == idx) return 0;
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    if (idx <= mid) {
      int tmp = 0;
      if (tree[n].idx > mid) tmp = e - mid;
      return query(l, b, mid, idx) + tmp;
    }
    int tmp = 0;
    if (tree[n].idx <= mid) tmp = mid - b + 1;
    return query(r, mid + 1, e, idx) + tmp;
    return 0;
  }
} st;

void solve() {
  int q; cin >> n >> q;
  n = (1 << n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
  while (q--) {
    int idx, x; cin >> idx >> x;
    st.upd(1, 1, n, idx, x);
    cout << st.query(1, 1, n, idx) << '\n';
    st.upd(1, 1, n, idx, a[idx]);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}