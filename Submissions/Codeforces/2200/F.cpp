#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] = max(tree[n], lazy[n]);
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = max(lazy[l], lazy[n]);
      lazy[r] = max(lazy[r], lazy[n]);
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = max(lazy[n], x);
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

void solve() {
  int n, m; cin >> n >> m;
  pair<int, int> a[n + 1], b[m + 1];
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    a[i] = {y, x};
  }
  for (int i = 1; i <= m; i++) {
    int x, y; cin >> x >> y;
    b[i] = {x, y};
  }

  sort(a + 1, a + n + 1);

  st.build(1, 1, n);
  set <pair<int, int>> se;
  int sum = 0, ans = 0;
  for (int i = n; i >= 1; i--) {
    auto [y, x] = a[i];

    while (se.size() > y) {
      auto it = se.begin();
      sum -= (*it).first;
      se.erase(it);
      st.upd(1, 1, n, se.size(), n, sum);
    }

    se.insert({x, y});
    sum += x;

    while (se.size() > y + 1) {
      auto it = se.begin();
      sum -= (*it).first;
      se.erase(it);
    }
    ans = max(ans, sum);

    while (se.size() > y) {
      auto it = se.begin();
      sum -= (*it).first;
      se.erase(it);
    }

    // cout << y << ' ' << sum << '\n';

    st.upd(1, 1, n, se.size(), n, sum);
  }

  while (se.size() > 0) {
    auto it = se.begin();
    sum -= (*it).first;
    se.erase(it);
    st.upd(1, 1, n, se.size(), n, sum);
  }

  for (int i = 1; i <= m; i++) {
    cout << max(ans, b[i].first + st.query(1, 1, n, 1, b[i].second)) << ' ';
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