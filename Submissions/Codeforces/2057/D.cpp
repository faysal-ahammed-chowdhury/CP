#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 2e9;
int a[N];

struct node {
  ll neg_mn, neg_mx, pos_mn, pos_mx, ans;
};

struct ST {
  node tree[4 * N];
  node merge(node l, node r) {
    node tmp;
    tmp.neg_mn = min(l.neg_mn, r.neg_mn);
    tmp.neg_mx = max(l.neg_mx, r.neg_mx);
    tmp.pos_mn = min(l.pos_mn, r.pos_mn);
    tmp.pos_mx = max(l.pos_mx, r.pos_mx);
    tmp.ans = max(l.ans, r.ans);
    tmp.ans = max(tmp.ans, r.neg_mx - l.neg_mn);
    tmp.ans = max(tmp.ans, l.pos_mx - r.pos_mn);
    return tmp;
  }
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {a[b] - b, a[b] - b, a[b] + b, a[b] + b, 0};
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
      tree[n] = {x - b, x - b, x + b, x + b, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {inf, -inf, inf, -inf, 0};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  cout << st.query(1, 1, n, 1, n).ans << '\n';

  while (q--) {
    int i, x; cin >> i >> x;
    st.upd(1, 1, n, i, x);
    cout << st.query(1, 1, n, 1, n).ans << '\n';
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