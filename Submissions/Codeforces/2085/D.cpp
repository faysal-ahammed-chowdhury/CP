#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 2e9;
int a[N];

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = {a[b], b};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = {x, b};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return { -inf, -1};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

void solve() {
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);

  int strt = n - k;
  while (true) {
    if (strt - k - 1 <= 0) break;
    strt = strt - k - 1;
  }

  ll ans = 0;
  for (int i = strt; i <= n; i += k + 1) {
    // cout << i << '\n';
    auto [mx, idx] = st.query(1, 1, n, 1, i);
    if (mx == -1) break;
    ans += mx;
    st.upd(1, 1, n, idx, -1);
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