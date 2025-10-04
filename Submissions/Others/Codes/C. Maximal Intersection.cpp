#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 7e5 + 9, inf = 2e9;

struct ST {
  array<int, 3> tree[4 * N];
  int lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n][0] += lazy[n];
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[r] += lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = {0, b, b};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
    if (tree[l][0] == tree[r][0]) {
      tree[n][1] = tree[l][1];
      tree[n][2] = tree[r][2];
    }
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] += x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = max(tree[l], tree[r]);
    if (tree[l][0] == tree[r][0]) {
      tree[n][1] = tree[l][1];
      tree[n][2] = tree[r][2];
    }
  }
  array<int, 3> query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return { -inf, -inf, -inf};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    array<int, 3> L = query(l, b, mid, i, j);
    array<int, 3> R = query(r, mid + 1, e, i, j);
    array<int, 3> ans = max(L, R);
    if (L[0] == R[0]) {
      ans[1] = L[1];
      ans[2] = R[2];
    }
    return ans;
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  pair<int, int> a[n + 1];
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
    v.push_back(a[i].first);
    v.push_back(a[i].second);
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());

  int mx = 0;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x = lower_bound(v.begin(), v.end(), a[i].first) - v.begin() + 1;
    int y = lower_bound(v.begin(), v.end(), a[i].second) - v.begin() + 1;
    mp[x] = a[i].first;
    mp[y] = a[i].second;
    a[i].first = x;
    a[i].second = y;
    mx = max(mx, a[i].second);
  }

  int ans = 0;
  st.build(1, 1, mx);
  for (int i = 1; i <= n; i++) {
    st.upd(1, 1, mx, a[i].first, a[i].second, 1);
  }

  for (int i = 1; i <= n; i++) {
    st.upd(1, 1, mx, a[i].first, a[i].second, -1);
    auto [val, l, r] = st.query(1, 1, mx, 1, mx);

    if (val == n - 1) {
      l = mp[l], r = mp[r];
      // cout << i << ' ' << val << ' ' << l << ' ' << r << '\n';
      ans = max(ans, r - l);
    }

    st.upd(1, 1, mx, a[i].first, a[i].second, 1);
  }

  cout << ans << '\n';

  return 0;
}