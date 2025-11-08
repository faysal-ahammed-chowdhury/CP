#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e5 + 9, mod = 1e9 + 7;
string s;

int fact[N], ifact[N];

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

int inverse(int x) {
  return power(x, mod - 2, mod);
}

void prec() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
  }
}

struct node {
  int freq[26];
};

struct ST {
  node tree[4 * N];
  node merge(node &l, node &r) {
    node ans;
    for (int c = 0; c < 26; c ++) {
      ans.freq[c] = l.freq[c] + r.freq[c];
    }
    return ans;
  }
  void build(int n, int b, int e) {
    if (b == e) {
      for (int c = 0; c < 26; c++) {
        tree[n].freq[c] = 0;
      }
      tree[n].freq[s[b] - 'a']++;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, char x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n].freq[x - 'a'] = 1;
      tree[n].freq[s[b] - 'a'] = 0;
      s[b] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) {
      node tmp;
      for (int c = 0; c < 26; c++) {
        tmp.freq[c] = 0;
      }
      return tmp;
    }
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    node L = query(l, b, mid, i, j);
    node R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

using T = array<int, 2>;
const T MOD = {127657753, 987654319};
const T p = {137, 277}; // change here

T operator + (T a, int x) {return {(a[0] + x) % MOD[0], (a[1] + x) % MOD[1]};}
T operator - (T a, int x) {return {(a[0] - x + MOD[0]) % MOD[0], (a[1] - x + MOD[1]) % MOD[1]};}
T operator * (T a, int x) {return {(int)((long long) a[0] * x % MOD[0]), (int)((long long) a[1] * x % MOD[1])};}
T operator + (T a, T x) {return {(a[0] + x[0]) % MOD[0], (a[1] + x[1]) % MOD[1]};}
T operator - (T a, T x) {return {(a[0] - x[0] + MOD[0]) % MOD[0], (a[1] - x[1] + MOD[1]) % MOD[1]};}
T operator * (T a, T x) {return {(int)((long long) a[0] * x[0] % MOD[0]), (int)((long long) a[1] * x[1] % MOD[1])};}
ostream& operator << (ostream& os, T hash) {return os << "(" << hash[0] << ", " << hash[1] << ")";}

T pw[N], ipw[N];
void prec2() {
  pw[0] =  {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i] = pw[i - 1] * p;
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
  vector<array<T, 2>> t; // (normal, rev) hash
  array<T, 2> merge(array<T, 2> l, array<T, 2> r) {
    l[0] = l[0] + r[0];
    l[1] = l[1] + r[1];
    return l;
  }
  void build(int node, int b, int e) {
    if (b == e) {
      t[node][0] = pw[b] * s[b];
      t[node][1] = pw[n - b + 1] * s[b];
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[node] = merge(t[l], t[r]);
  }
  void upd(int node, int b, int e, int i, char x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      t[node][0] = pw[b] * x;
      t[node][1] = pw[n - b + 1] * x;
      return;
    }
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    t[node] = merge(t[l], t[r]);
  }
  array<T, 2> query(int node, int b, int e, int i, int j) {
    if (b > j || e < i) return {T({0, 0}), T({0, 0})};
    if (b >= i && e <= j) return t[node];
    int mid = (b + e) >> 1, l = node << 1, r = l | 1;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
  }
  Hashing() {}
  Hashing(string _s) {
    n = _s.size();
    s = "." + _s;
    t.resize(4 * n + 1);
    build(1, 1, n);
  }
  void upd(int i, char c) {
    upd(1, 1, n, i, c);
    s[i] = c;
  }
  T get_hash(int l, int r) { // 1 - indexed
    return query(1, 1, n, l, r)[0] * ipw[l - 1];
  }
  T rev_hash(int l, int r) { // 1 - indexed
    return query(1, 1, n, l, r)[1] * ipw[n - r];
  }
  T get_hash() {
    return get_hash(1, n);
  }
  bool is_palindrome(int l, int r) {
    return get_hash(l, r) == rev_hash(l, r);
  }
};


void solve() {
  int n, q; cin >> n >> q;
  cin >> s;
  Hashing hs(s);
  s = '.' + s;
  st.build(1, 1, n);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int i; char c; cin >> i >> c;
      if (c == s[i]) continue;
      st.upd(1, 1, n, i, c);
      hs.upd(i, c);
    }
    else {
      int l, r; cin >> l >> r;

      node tmp = st.query(1, 1, n, 1, n);
      int odd = 0;
      char odd_c = '.';
      for (int c = 0; c < 26; c++) {
        if (tmp.freq[c] & 1) {
          odd++;
          odd_c = char(c + 'a');
        }
      }

      if (odd > 1) {
        cout << 0 << ' ';
        continue;
      }

      int left = l - 1, right = n - r;
      int len = right;
      if (left <= right) len = left;

      bool ok = hs.get_hash(1, len) == hs.rev_hash(n - len + 1, n);
      int rr = n - l + 1, ll = n - r + 1;

      if (!ok) {
        cout << 0 << ' ';
        continue;
      }

      if (r < ll) {
        ok &= hs.is_palindrome(r + 1, ll - 1);
        node tmp1 = st.query(1, 1, n, l, r);
        node tmp2 = st.query(1, 1, n, ll, rr);
        for (int c = 0; c < 26; c++) {
          ok &= tmp1.freq[c] == tmp2.freq[c];
          if (!ok) break;
        }
        cout << ok << ' ';
        continue;
      }
      else if (rr < l) {
        ok &= hs.is_palindrome(rr + 1, l - 1);
        node tmp1 = st.query(1, 1, n, l, r);
        node tmp2 = st.query(1, 1, n, ll, rr);
        for (int c = 0; c < 26; c++) {
          ok &= tmp1.freq[c] == tmp2.freq[c];
          if (!ok) break;
        }
        cout << ok << ' ';
        continue;
      }

      if (!ok) {
        cout << 0 << ' ';
        continue;
      }

      node tmp1 = st.query(1, 1, n, l, r);

      if (ll >= l) {
        node tmp2 = st.query(1, 1, n, r + 1, rr);
        for (int c = 0; c < 26; c++) {
          tmp1.freq[c] -= tmp2.freq[c];
          ok &= tmp1.freq[c] >= 0;
          if (!ok) break;
        }
      }
      else if (l >= ll) {
        node tmp2 = st.query(1, 1, n, ll, l - 1);
        for (int c = 0; c < 26; c++) {
          tmp1.freq[c] -= tmp2.freq[c];
          ok &= tmp1.freq[c] >= 0;
          if (!ok) break;
        }
      }

      if (!ok) {
        cout << 0 << ' ';
        continue;
      }

      int tot = 0, inv = 1;
      for (int c = 0; c < 26; c++) {
        ok &= tmp1.freq[c] >= 0;
        tot += tmp1.freq[c];
        inv = 1ll * inv * ifact[tmp1.freq[c] / 2] % mod;
      }

      int ans = 1ll * fact[tot / 2] * inv % mod;
      cout << (ok ? ans : 0) << ' ';
    }
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();
  prec2();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}