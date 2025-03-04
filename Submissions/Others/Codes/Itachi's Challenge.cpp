#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;
int a[N];

int power(int b, long long p, int m) {
  if(p == 0) return 1 % m;
  if(p & 1) {
    int val = power(b, p / 2, m);
    return ((1LL * val * val) % m) * b % m;
  }
  else {
    int val = power(b, p / 2, m);
    return (1LL * val * val) % m;
  }
}

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] += (1ll * lazy[n] * (e - b + 1) % mod);
    tree[n] %= mod;
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[l] %= mod;
      lazy[r] += lazy[n];
      lazy[r] %= mod;
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = a[b];
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
      lazy[n] = x; 
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

int geo_sum(int a, int r, long long n) {
  int tmp = power(r, n, mod) - 1;
  if (tmp < 0) tmp += mod;
  int ans = 1ll * a * tmp % mod;
  int inv = power(r - 1, mod - 2, mod);
  ans = 1ll * ans * inv % mod;
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
  int q; cin >> q;
  while (q--) {
    int l, r; long long k; cin >> l >> r >> k;
    int len = r - l + 1;
    int x = st.query(1, 1, n, l, r);
    int add = geo_sum(x, len + 1, k);
    st.upd(1, 1, n, l, r, add);
  }

  for (int i = 1; i <= n; i++) {
    cout << st.query(1, 1, n, i, i) << " \n"[i == n];
  }

  return 0;
}