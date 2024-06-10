#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, Q = 5e4 + 9;
int deleted_idx;

struct ST {
  pair<int, int> tree[4 * (N + Q)];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n].first = 0;
      tree[n].second = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].second = tree[l].second + tree[r].second;
  }
  void upd(int n, int b, int e, int i, int x1, int x2) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n].first = x1;
      tree[n].second = x2;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x1, x2);
    upd(r, mid + 1, e, i, x1, x2);
    tree[n].second = tree[l].second + tree[r].second;
  }
  pair<int, int> query(int n, int b, int e, int x) {
    if (b > e) return { -1, -1};
    if (tree[n].second < x) return {tree[n].second, -1};
    if (b == e) {
      deleted_idx = b;
      return tree[n];
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, x);
    if (L.second != -1) return L;
    pair<int, int> R = query(r, mid + 1, e, x - L.first);
    return R;
  }
} st;

int cs;
void solve() {
  cout << "Case " << ++cs << ":\n";
  int n, q; cin >> n >> q;
  int end = n + q + 5;
  st.build(1, 1, end);
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    st.upd(1, 1, end, i, x, 1);
  }

  int id = n;
  while (q--) {
    char c; cin >> c;
    if (c == 'a') {
      int p; cin >> p;
      st.upd(1, 1, end, ++id, p, 1);
    }
    else {
      int k; cin >> k;
      pair<int, int> ans = st.query(1, 1, end, k);
      if (ans.second == -1) cout << "none\n";
      else {
        cout << ans.first << '\n';
        st.upd(1, 1, end, deleted_idx, 0, 0);
      }
    }
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