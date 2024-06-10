#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9, M = 2e5 + 9;
int n, h[N], a[N];
ll dp[N];

struct ST {
  ll tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, ll x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = max(tree[n], x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  ll query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, M);

  for (int i = 1; i <= n; i++) {
    dp[i] = a[i];
    if (h[i] != 1) {
      ll mx = st.query(1, 1, M, 1, h[i] - 1);
      mx += a[i];
      dp[i] = max(dp[i], mx);
    }
    st.upd(1, 1, M, h[i], dp[i]);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << '\n';

  return 0;
}