#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300000 + 9, inf = 2e9, mod = 1e9 + 9;
int a[N], fib[N];
 
int get(int first, int second, int k) {
  if (k == 1) return first;
  if (k == 2) return second;
  int x = ((1ll * first * fib[k - 2] % mod) + (1ll * second * fib[k - 1] % mod)) % mod;
  return x;
}

int sum(int first, int second, int n) {
  int x = get(first, second, n + 2) - second;
  if (x < 0) x += mod;
  return x;
}
 
struct ST {
  int tree[4 * N];
  array<int, 2> lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n][0] == -1) return;
    int len = e - b + 1;
    tree[n] = (tree[n] + sum(lazy[n][0], lazy[n][1], len)) % mod;

    // cout << n << ' ' << b << ' ' << e << ' ' << sum(lazy[n][0], lazy[n][1], len) << '\n';
    if (b != e) {
      int l = n << 1, r = l + 1;
      if (lazy[l][0] == -1) lazy[l] = {0, 0};
      lazy[l][0] = (lazy[l][0] + lazy[n][0]) % mod;
      lazy[l][1] = (lazy[l][1] + lazy[n][1]) % mod;

      if (lazy[r][0] == -1) lazy[r] = {0, 0};
      lazy[r][0] = (lazy[r][0] + get(lazy[n][0], lazy[n][1], ((len + 1) / 2) + 1)) % mod;
      lazy[r][1] = (lazy[r][1] + get(lazy[n][0], lazy[n][1], ((len + 1) / 2) + 2)) % mod;
    }
    lazy[n] = {-1, -1};
  }
  void build(int n, int  b, int e) {
    lazy[n] = {-1, -1};
    if (b == e) {
      tree[n] = a[b]; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = (tree[l] + tree[r]) % mod;
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      int first = fib[b - i + 1];
      int second = fib[b - i + 2];
      lazy[n] = {first, second}; 
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j);
    upd(r, mid + 1, e, i, j);
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

  fib[1] = 1, fib[2] = 1;
  for (int i = 3; i < N; i++) {
    fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
  }
 
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
 
  st.build(1, 1, n);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      st.upd(1, 1, n, l, r);
    }
    else {
      int l, r; cin >> l >> r;
      cout << st.query(1, 1, n, l, r) << '\n';
    }
  }
 
  return 0;
}