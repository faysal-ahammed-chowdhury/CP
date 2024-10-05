#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 9;

struct ST {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R);
  }
} st, st2;

bool ok(int len, int have, int n) {
  return st.query(1, 1, n, 1, len) <= have;
}

void solve() {
  int n, d; cin >> n >> d;
  array<int, 2> a[n + 1], sorted[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0];
    sorted[i][1] = a[i][0];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i][1];
    sorted[i][0] = a[i][1];
  }

  sort(a + 1, a + n + 1);
  sort(sorted + 1, sorted + n + 1);

  map<array<int, 2>, int> mp;
  for (int i = 1; i <= n; i++) {
    mp[ {sorted[i][1], sorted[i][0]}] = i;
  }

  st.build(1, 1, n);
  st2.build(1, 1, n);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int have = d - a[i][0];
    if (have < 0) continue;

    st.upd(1, 1, n, mp[a[i]], a[i][1]);
    st2.upd(1, 1, n, mp[a[i]], 1);

    int l = 0, r = n, cnt = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid, have, n)) {
        cnt = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    ans = max(ans, st2.query(1, 1, n, 1, cnt));
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