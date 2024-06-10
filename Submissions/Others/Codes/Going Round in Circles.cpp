#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9, inf = 1e9;
int a[N];

struct ST {
  pair<int, ll> tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n].first = (a[b] ? b : inf);
      tree[n].second = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = {min(tree[l].first, tree[r].first), tree[l].second + tree[r].second};
  }
  void upd(int n, int b, int e, int i, int x1, int x2) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n].first = x1;
      tree[n].second = x2;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x1, x2);
    upd(r, mid + 1, e, i, x1, x2);
    tree[n] = {min(tree[l].first, tree[r].first), tree[l].second + tree[r].second};
  }
  pair<int, ll> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {inf, 0};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, ll> L = query(l, b, mid, i, j);
    pair<int, ll> R = query(r, mid + 1, e, i, j);
    return {min(L.first, R.first), L.second + R.second};
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
  while (q--) {
    int type, l, r; cin >> type >> l >> r;
    if (type == 1) {
      while (l <= r) {
        int mn = st.query(1, 1, n, l, r).first;
        if (mn <= r) {
          a[mn] = a[mn] << 1;
          int msb = __lg(a[mn]);
          a[mn] -= (1 << msb);
          a[mn] += 1;
          int idx = mn;
          int cnt = __builtin_popcount(a[mn]);
          if (a[mn] == (1 << cnt) - 1) idx = inf;
          st.upd(1, 1, n, mn, idx, a[mn]);
        }
        l = mn + 1;
      }
    }
    else {
      cout << st.query(1, 1, n, l , r).second << '\n';
    }
  }

  return 0;
}