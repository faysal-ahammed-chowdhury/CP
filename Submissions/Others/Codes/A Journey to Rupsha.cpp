#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;

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
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] = (tree[n] + (1ll * lazy[n] * (e - b + 1) % mod)) % mod;
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = (lazy[l] + lazy[n]) % mod;
      lazy[r] = (lazy[r] + lazy[n]) % mod;
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
    tree[n] = (tree[l] + tree[r]) % mod;
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
    tree[n] = (tree[l] + tree[r]) % mod; 
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0; 
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R) % mod;
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    long long x; cin >> x;
    a[i] = x % mod;
  }

  st.build(1, 1, n);
  while (q--) {
    string type; cin >> type;
    if (type == "Ask") {
      int i; cin >> i;
      int pw = st.query(1, 1, n, 1, i);
      int ans = 1ll * a[i] * power(3, pw, mod) % mod;
      cout << ans << '\n';
    }
    else {
      int l, r; cin >> l >> r;
      int a = 0, b = 1;
      st.upd(1, 1, n, l, l, a);
      if (l != r) {
        st.upd(1, 1, n, l + 1, r, b);
      }
      int x = (-((b * (r - l)) + a)) % mod;
      if (x < 0) x += mod;
      if (r + 1 <= n) st.upd(1, 1, n, r + 1, r + 1, x);
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << st.query(1, 1, n, i, i) << ' ';
  // }
  // cout << '\n';

  // cout << st.query(1, 1, n, 1, 5) << '\n';
  // cout << (10 * power(3, 7, mod) % mod) << '\n';

  return 0;
}