#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9, mod = 1e9 + 7, B = 30;
int a[N], l[N], r[N], x[N];

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] |= lazy[n]; // change here
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] |= lazy[n]; // change here
      lazy[r] |= lazy[n]; // change here
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = a[b]; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] | tree[r]; // change here
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = x; // change here
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = tree[l] | tree[r]; // change here
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0; // return appropriate value
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L | R; // change here
  }
} st;

struct ST2 {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == -1) return;
    tree[n] &= lazy[n]; // change here
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] &= lazy[n]; // change here
      lazy[r] &= lazy[n]; // change here
    }
    lazy[n] = -1;
  }
  void build(int n, int  b, int e) {
    lazy[n] = -1;
    if (b == e) {
      tree[n] = a[b]; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] & tree[r]; // change here
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = x; // change here
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = tree[l] & tree[r]; // change here
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return ((1 << 30) - 1); // return appropriate value
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L & R; // change here
  }
} st2;

int power(int b, int p, int m) {
  if (p == 0) return 1 % m;
  if (p & 1) {
    int val = power(b, p / 2, m);
    return ((1LL * val * val) % m) * b % m;
  }
  else {
    int val = power(b, p / 2, m);
    return (1LL * val * val) % m;
  }
}

void solve() {
  int n, m; cin >> n >> m;
  st.build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    cin >> l[i] >> r[i] >> x[i];
    st.upd(1, 1, n, l[i], r[i], x[i]);
  }
  for (int i = 1; i <= n; i++) {
    a[i] = st.query(1, 1, n, i, i);
  }
  st2.build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    st2.upd(1, 1, n, l[i], r[i], x[i]);
  }
  for (int i = 1; i <= n; i++) {
    a[i] = st2.query(1, 1, n, i, i);
  }

  int ans = 0;
  for (int k = 0; k < B; k++) {
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] & (1 << k)) {
        cnt1++;
      }
      else {
        cnt0++;
      }
    }
    if (cnt1 != 0) {
      ans += 1ll * power(2, (cnt1 + cnt0 - 1), mod) * (1 << k) % mod;
      ans %= mod;
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}