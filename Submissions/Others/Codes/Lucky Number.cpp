#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, Q = 1429431 + 9;
int idx, ans[N];

struct ST {
  pair<int, int> tree[4 * Q];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n].first = 0;
      tree[n].second = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = tree[l].first + tree[r].first;
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
    tree[n].first = tree[l].first + tree[r].first;
    tree[n].second = tree[l].second + tree[r].second;
  }
  pair<int, int> query(int n, int b, int e, int x) {
    if (b > e) return { -1, -1};
    if (tree[n].second < x) return {tree[n].second, -1};
    if (b == e) {
      idx = b;
      return tree[n];
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, x);
    if (L.second != -1) return L;
    pair<int, int> R = query(r, mid + 1, e, x - L.first);
    return R;
  }
} st;

void prec() {
  int n = 1429433;
  st.build(1, 1, n);
  for (int i = 1, j = 1; j <= n; i++, j += 2) {
    st.upd(1, 1, n, i, j, 1);
  }
  ans[1] = 1;
  for (int i = 2; i <= 100000; i++) {
    ans[i] = st.query(1, 1, n, i).first;
    for (int j = ans[i], jj = 0; j <= n; j += ans[i], jj++) {
      idx = -1;
      st.query(1, 1, n, j - jj);
      if (idx != -1) st.upd(1, 1, n, idx, 0, 0);
    }
  }
}

int cs;
void solve() {
  int n; cin >> n;
  cout << "Case " << ++cs << ": " << ans[n] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}