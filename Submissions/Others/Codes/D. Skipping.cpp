#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 4e5 + 9;
const ll inf = 1e18;
int n, a[N], b[N];
ll psum[N], ans[N];

struct ST {
  ll tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = inf;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, ll x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = min(tree[n], x);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = min(tree[l], tree[r]);
  }
  ll query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return min(L, R);
  }
} st;

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];
    ans[i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  // cout << sorted_idx[1] << '\n';
  st.build(1, 1, n);
  st.upd(1, 1, n, b[1], a[1]);
  // cout << st.query(1, 1, n, 3, 4) << '\n';
  ans[1] = a[1];

  for (int i = 2; i <= n; i++) {
    ll mn = st.query(1, 1, n, i, n);
    // cout << i << ' ' << mn << '\n';
    if (mn >= inf) break;
    ans[i] = psum[i] - mn;
    ll x = mn + a[i];
    st.upd(1, 1, n, b[i], x);
  }

  ll mx = 0;
  for (int i = 1; i <= n; i++) {
    mx = max(mx, ans[i]);
  }
  cout << mx << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}