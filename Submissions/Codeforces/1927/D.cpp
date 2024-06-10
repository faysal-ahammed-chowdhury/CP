#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, inf = 1e9;
int a[N];

struct node {
  int mx, mn, mx_idx, mn_idx;
};

node merge(node l, node r) {
  node ans;
  ans.mx = max(l.mx, r.mx);
  ans.mn = min(l.mn, r.mn);
  if (l.mx > r.mx) {
    ans.mx_idx = l.mx_idx;
  }
  else {
    ans.mx_idx = r.mx_idx;
  }

  if (l.mn < r.mn) {
    ans.mn_idx = l.mn_idx;
  }
  else {
    ans.mn_idx = r.mn_idx;
  }
  return ans;
}

struct ST {
  node tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n].mx = a[b];
      tree[n].mn = a[b];
      tree[n].mx_idx = b;
      tree[n].mn_idx = b;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }

  node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) {
      node tmp = {-inf, inf, -1, -1};
      return tmp;
    };
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R); 
  }
} st;


void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    node ans = st.query(1, 1, n, l, r);
    if (ans.mx_idx != ans.mn_idx) {
      if (ans.mx_idx > ans.mn_idx) {
        swap(ans.mx_idx, ans.mn_idx);
      }
      cout << ans.mx_idx << ' ' << ans.mn_idx << '\n';
    }
    else {
      cout << -1 << ' ' << -1 << '\n';
    }
  }

  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}