#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9;
int n, k, a[N];

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
      tree[n] = x == 0;
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
} st;

bool ok(int len) {
  for (int i = 1; i + len - 1 <= n; i++) {
    int l = i, r = i + len - 1;
    if (st.query(1, 1, n, l + 1, r) > 0) continue;
    if (a[r] - a[l] < k) return true;
  }
  return false;
}

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  st.build(1, 1, n);
  for (int i = 2; i <= n; i++) {
    int flag = (a[i] - a[i - 1]) <= 1;
    st.upd(1, 1, n, i, flag);
  }

  int l = 1, r = n, ans = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
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