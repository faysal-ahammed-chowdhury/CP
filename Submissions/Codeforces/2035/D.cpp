#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 9, inf = 1e10 + 69, mod = 1e9 + 7;
int a[N], pw[N];

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

struct ST {
  pair<int, int> tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n].first = (pw[b] ? b : -inf);
      tree[n].second = pw[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = {max(tree[l].first, tree[r].first), tree[l].second + tree[r].second};
  }
  void upd(int n, int b, int e, int i, int x1, int x2) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n].first = x1;
      tree[n].second += x2;
      tree[n].second = max(0ll, tree[n].second);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x1, x2);
    upd(r, mid + 1, e, i, x1, x2);
    tree[n] = {max(tree[l].first, tree[r].first), tree[l].second + tree[r].second};
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return { -inf, 0};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return {max(L.first, R.first), L.second + R.second};
  }
} st;


inline bool better (pair <int, int> P, pair <int, int> Q) { // from AlphaQ
  auto [u, x] = P; auto [v, y] = Q;
  // u * 2^x + v * 2^y <= u + v * 2^(x+y) --> u <= v * 2^y
  long long bound = v;
  for (int i = 0; i < y and bound < inf; ++i) bound *= 2;
  return u <= bound; 
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int &x = a[i];
    pw[i] = 0;
    while (x > 0 and x % 2 == 0) {
      pw[i]++;
      x /= 2;
    }
  }
  st.build(1, 1, n);

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (a[i] * (power(2, pw[i], mod)) % mod);
    ans %= mod;
    int l = 1, r = i - 1;
    // cout << i << ": ";
    while (r >= l) {
      int mx = st.query(1, 1, n, 1, r).first;
      if (mx < 1) break;
      int ex1 = st.query(1, 1, n, mx, mx).second;
      int ex2 = st.query(1, 1, n, i, i).second;
      int val1 = a[mx];
      int val2 = a[i];
      if (better(make_pair(val1, ex1), make_pair(val2, ex2))) {
        ans -= (a[mx] * (power(2, ex1, mod)) % mod);
        if (ans < 0) ans += mod;
        ans += a[mx];
        ans %= mod;
        ans -= (a[i] * (power(2, ex2, mod)) % mod);
        if (ans < 0) ans += mod;
        ans += (a[i] * (power(2, ex1 + ex2, mod)) % mod);
        ans %= mod;
        st.upd(1, 1, n, mx, -inf, -ex1);
        st.upd(1, 1, n, i, i, ex1);
      }
      else break;
      r = mx - 1;
    }
    // for (int k = 1; k <= n; k++) {
    //   cout << st.query(1, 1, n, k, k).second << ',';
    // }
    // cout << '\n';
    cout << ans << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}