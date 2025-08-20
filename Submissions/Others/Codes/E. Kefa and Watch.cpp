#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;

int power(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

using T = array<int, 2>;
const T MOD = {998244353, 987654319};
const T p = {257, 1009}; // change here

T operator + (T a, int x) {return {(a[0] + x) % MOD[0], (a[1] + x) % MOD[1]};}
T operator - (T a, int x) {return {(a[0] - x + MOD[0]) % MOD[0], (a[1] - x + MOD[1]) % MOD[1]};}
T operator * (T a, int x) {return {(int)((long long) a[0] * x % MOD[0]), (int)((long long) a[1] * x % MOD[1])};}
T operator + (T a, T x) {return {(a[0] + x[0]) % MOD[0], (a[1] + x[1]) % MOD[1]};}
T operator - (T a, T x) {return {(a[0] - x[0] + MOD[0]) % MOD[0], (a[1] - x[1] + MOD[1]) % MOD[1]};}
T operator * (T a, T x) {return {(int)((long long) a[0] * x[0] % MOD[0]), (int)((long long) a[1] * x[1] % MOD[1])};}
ostream& operator << (ostream& os, T hash) {return os << "(" << hash[0] << ", " << hash[1] << ")";}

T pw[N], ipw[N], pref_pw[N];
void prec() {
  pw[0] =  {1, 1};
  pref_pw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i] = pw[i - 1] * p;
    pref_pw[i] = pref_pw[i - 1] + pw[i];
  }
  ipw[0] =  {1, 1};
  T ip = {power(p[0], MOD[0] - 2, MOD[0]), power(p[1], MOD[1] - 2, MOD[1])};
  for (int i = 1; i < N; i++) {
    ipw[i] = ipw[i - 1] * ip;
  }
}

struct Hashing {
  int n;
  string s; // 1 - indexed
  vector<T> t;
  vector<T> lazy;
  T merge(T l, T r) {
    l = l + r;
    return l;
  }
  void push(int n, int b, int e) {
    if (lazy[n][0] == 0) return;
    t[n] = lazy[n] * (pref_pw[e] - pref_pw[b - 1]);
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n];
      lazy[r] = lazy[n];
    }
    lazy[n][0] = 0;
  }
  void build(int node, int b, int e) {
    if (b == e) {
      t[node] = pw[b] * s[b];
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = merge(t[l], t[r]);
  }
  void upd(int node, int b, int e, int i, int j, char x) {
    push(node, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[node] = {x, x};
      push(node, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    t[node] = merge(t[l], t[r]);
  }
  T query(int node, int b, int e, int i, int j) {
    push(node, b, e);
    if (b > j || e < i) return T({0, 0});
    if (b >= i && e <= j) return t[node];
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
  }
  Hashing() {}
  Hashing(string _s) {
    n = _s.size();
    s = "." + _s;
    t.resize(4 * n + 1);
    lazy.resize(4 * n + 1);
    build(1, 1, n);
  }
  void upd(int i, int j, char c) {
    upd(1, 1, n, i, j, c);
    s[i] = c;
  }
  T get_hash(int l, int r) { // 1 - indexed
    return query(1, 1, n, l, r) * ipw[l - 1];
  }
  T get_hash() {
    return get_hash(1, n);
  }
};

Hashing hs;

bool f(int l, int r, int d) {
  int segment = (r - l + 1) / d;
  if (segment == 1) return true;
  
  return hs.get_hash(l, r - d) == hs.get_hash(l + d, r);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  int n, m, k; cin >> n >> m >> k;
  string s; cin >> s;
  hs = Hashing(s);

  int q = m + k;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      char c; cin >> c;
      hs.upd(l, r, c);
    }
    else {
      int l, r, d; cin >> l >> r >> d;
      // bool ok = true;
      // for (int i = l; i + d <= r; i++) {
      //   ok &= hs.get_hash(i, i) == hs.get_hash(i + d, i + d);
      // }

      int x = (r - l + 1) / d;
      bool ok = f(l, l + d * x - 1, d);
      int len = r - (l + d * x) + 1;
      ok &= hs.get_hash(l, l + len - 1) == hs.get_hash(l + d * x, r);
      if (ok) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}