#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9, inf = 1e10;
int n, a[N];

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = {a[b], a[b]};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = max(tree[l].first, tree[r].first);
    tree[n].second = min(tree[l].second, tree[r].second);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return { -inf, inf};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return {max(L.first, R.first), min(L.second, R.second)};
  }
} st;

bool ok1(int i, int val) {
  auto [mx, mn] = st.query(1, 1, n, 1, i);
  return mx > val;
}

bool ok2(int i, int val) {
  auto [mx, mn] = st.query(1, 1, n, i, n);
  return mx > val;
}

bool ok3(int i, int val) {
  auto [mx, mn] = st.query(1, 1, n, 1, i);
  return mn < val;
}

bool ok4(int i, int val) {
  auto [mx, mn] = st.query(1, 1, n, i, n);
  return mn < val;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);

  auto [x, y] = st.query(1, 1, n, 1, n);
  int ans = x - y;

  for (int i = 1; i <= n; i++) {
    int mx = a[i];
    int l = 1, r = n, l1 = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok1(mid, mx)) {
        l1 = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }

    if (l1 == -1) continue;
    l = 1, r = n; int r1 = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok2(mid, mx)) {
        r1 = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    if (r1 == -1) continue;

    auto [mx1, mn1] = st.query(1, 1, n, 1, l1 - 1);
    auto [rmx, rmn] = st.query(1, 1, n, l1, r1);
    auto [mx2, mn2] = st.query(1, 1, n, r1 + 1, n);

    int x = max({mx1, (rmx - (rmx - mx)), mx2});
    int y = min({mn1, (rmn - (rmx - mx)), mn2});
    ans = min(ans, abs(x - y));
  }

  for (int i = 1; i <= n; i++) {
    int mn = a[i];
    int l = 1, r = n, l1 = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok3(mid, mn)) {
        l1 = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }

    if (l1 == -1) continue;
    l = 1, r = n; int r1 = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok4(mid, mn)) {
        r1 = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    if (r1 == -1) continue;

    auto [mx1, mn1] = st.query(1, 1, n, 1, l1 - 1);
    auto [rmx, rmn] = st.query(1, 1, n, l1, r1);
    auto [mx2, mn2] = st.query(1, 1, n, r1 + 1, n);

    int x = max({mx1, (rmx + (mn - rmn)), mx2});
    int y = min({mn1, (rmn + (mn - rmn)), mn2});
    ans = min(ans, abs(x - y));
  }

  cout << ans << '\n';
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