#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
int a[N];
int spf[N];
map<int, int> pf[N];
set<int> prime_pos[N];

void spf_sieve() {
  for (int i = 2; i < N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < N; i++) {
    if (spf[i] == i) {
      for (int j = i; j < N; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

struct ST {
  ll tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r];
  }
  ll query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return (L + R);
  }
} st;

void prec() {
  for (int i = 1; i < N; i++) {
    int x = i;
    while (x > 1) {
      int p = spf[x], pw = 0;
      while (x % p == 0) {
        pw++;
        x /= p;
      }
      pf[i][p] = pw;
    }

    x = a[i];
    while (x > 1) {
      int p = spf[x], pw = 0;
      while (x % p == 0) {
        pw++;
        x /= p;
      }
      prime_pos[p].insert(i);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  prec();

  st.build(1, 1, n);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      cout << st.query(1, 1, n, l, r) << '\n';
    }
    else {
      int l, r, g; cin >> l >> r >> g;
      for (auto [p, pw] : pf[g]) {
        auto it = prime_pos[p].lower_bound(l);
        while (it != prime_pos[p].end() and *it <= r) {
          auto idx = *it;
          int val = st.query(1, 1, n, idx, idx);
          int tmp = pw;
          while (tmp-- and val % p == 0) {
            val /= p;
          }
          st.upd(1, 1, n, idx, val);
          // cout << p << ' ' << idx << ' ' << val << '\n';
          if (val % p != 0) prime_pos[p].erase(it);
          it = prime_pos[p].lower_bound(idx + 1);
        }
      }
    }
  }

  return 0;
}