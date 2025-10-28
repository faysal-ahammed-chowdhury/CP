#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;

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
      tree[n] += x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r];
  }
  void upd_set(int n, int b, int e, int i) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd_set(l, b, mid, i);
    upd_set(r, mid + 1, e, i);
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

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    st.upd(1, 1, N - 1, a[i], 1);
  }

  int ans = 1;
  for (int i = 1; i <= n; i++) {
    int x = i;
    int need = st.query(1, 1, N - 1, 1, x - 1);
    need += st.query(1, 1, N - 1, 3 * x + 1, 4 * x - 1);
    need += st.query(1, 1, N - 1, x + 1, 3 * x - 1);
    need -= st.query(1, 1, N - 1, 2 * x, 2 * x);
    if (need <= k) ans = max(ans, x);
  }
  cout << ans << '\n';

  for (int i = 1; i <= n; i++) {
    st.upd_set(1, 1, N - 1, a[i]);
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  st.build(1, 1, N - 1);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}