#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9, inf = 2e9;
int a[N], ans[N];
int n;

struct ST {
  int tree[4 * N];
  int tree2[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = a[b];
      tree2[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
    tree2[n] = max(tree2[l], tree2[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = x;
      tree2[n] = -x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = min(tree[l], tree[r]);
    tree2[n] = max(tree2[l], tree2[r]);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return {inf, -inf};
    if (b >= i && e <= j) return {tree[n], tree2[n]};
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return {min(L.first, R.first), max(L.second, R.second)};
  }
  pair<int, int> get_first(int n, int b, int e, int l, int r, int x) {
    if (b > r || e < l) return { -1, -1};
    if (tree[n] >= x) return { -1, -1};

    if (b == e) return {tree[n], b};

    int tm = b + (e - b) / 2;
    pair<int, int> left = get_first(2 * n, b, tm, l, r, x);
    if (left.second != -1) return left;
    return get_first(2 * n + 1, tm + 1, e, l , r, x);
  }
  int get_first2(int n, int b, int e, int l, int r, int x) {
    if (b > r || e < l) return -1;
    if (tree2[n] <= x) return -1;

    if (b == e) return b;

    int tm = b + (e - b) / 2;
    int left = get_first2(2 * n, b, tm, l, r, x);
    if (left != -1) return left;
    return get_first2(2 * n + 1, tm + 1, e, l , r, x);
  }
} st;

void solve() {
  cin >> n;
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pq.push({a[i], i});
    ans[i] = -1;
  }
  st.build(1, 1, n);

  while (!pq.empty()) {
    auto [x, i] = pq.top(); pq.pop();
    // cout << i << '\n';
    if (ans[i] != -1) x = ans[i];
    ans[i] = x;
    st.upd(1, 1, n, i, inf);
    while (true) {
      auto [val, idx] = st.get_first(1, 1, n, i, n, x);
      if (idx == -1) break;
      ans[idx] = x;
      st.upd(1, 1, n, idx, inf);
      while (true) {
        auto idx2 = st.get_first2(1, 1, n, 1, idx, val);
        if (idx2 == -1) break;
        ans[idx2] = x;
        st.upd(1, 1, n, idx2, inf);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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