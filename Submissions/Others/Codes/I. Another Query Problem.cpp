#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
const ll inf = 1e18;

pair<ll, ll> merge(pair<ll, ll> l, pair<ll, ll> r) {
  l.first = min(l.first, r.first);
  l.second = max(l.second, r.second);
  return l;
}

struct ST {
  pair<ll, ll> tree[4 * N];
  ll lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n].first += lazy[n];
    tree[n].second += lazy[n];
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[r] += lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = {0, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, ll x) {
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
    tree[n] = merge(tree[l], tree[r]);
  }
  pair<ll, ll> query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return {inf, -inf};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<ll, ll> L = query(l, b, mid, i, j);
    pair<ll, ll> R = query(r, mid + 1, e, i, j);
    return merge(L, R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  st.build(1, 1, n);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int l, r; cin >> l >> r;
      if (l == r) {
        cout << 1 << '\n';
        continue;
      }
      pair<ll, ll> ans = st.query(1, 1, n, l + 1, r);
      if (ans.first == 0 and ans.second == 0) {
        cout << 1 << '\n';
      }
      else {
        cout << 0 << '\n';
      }
    }
    else {
      int l, r; ll a, b; cin >> l >> r >> a >> b;
      st.upd(1, 1, n, l, l, a);
      if (l != r) {
        st.upd(1, 1, n, l + 1, r, b);
      }
      ll x = (b * (r - l)) + a;
      st.upd(1, 1, n, r + 1, r + 1, -x);
    }
  }

  return 0;
}