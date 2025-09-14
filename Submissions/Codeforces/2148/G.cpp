#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#include "debug.h"

template <typename T> using o_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
const int N = 2e5 + 9;
int spf[N];

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
  int tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] += x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;


void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  map<int, o_set<pair<int, int>>> mp;

  int gc = 0;
  st.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    gc = __gcd(gc, a[i]);
    int x = a[i];
    while (x > 1) {
      int p = spf[x], ex = 0;
      while (x % p == 0) {
        ex++;
        x /= p;
      }
      st.upd(1, 1, n, p, 1);
      mp[p].insert({ex, i});
    }

    x = gc;
    vector<pair<int, int>> v;
    while (x > 1) {
      int p = spf[x], ex = 0;
      while (x % p == 0) {
        ex++;
        x /= p;
      }
      v.push_back({p, ex});
    }

    int ans = 0;
    int last = 0;
    for (auto [p, ex] : v) {
      ans = max(ans, st.query(1, 1, n, last + 1, p - 1));
      last = p;
      ans = max(ans, (int)mp[p].order_of_key({ex, 1e9}));
    }
    ans = max(ans, st.query(1, 1, n, last + 1, n));

    // for (int i = 0; i < mp[2].size(); i++) {
    //   cout << (*mp[2].find_by_order(i)).first << ' ';
    // }
    // cout << '\n';

    cout << ans << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}