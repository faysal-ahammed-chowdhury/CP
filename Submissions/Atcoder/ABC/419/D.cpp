#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;

struct ST {
  pair<int, int> tree[4 * N];
  int lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    swap(tree[n].first, tree[n].second);
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] ^= lazy[n];
      lazy[r] ^= lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n] = {0, 1};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n].first = tree[l].first + tree[r].first;
    tree[n].second = tree[l].second + tree[r].second;
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] ^= x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n].first = tree[l].first + tree[r].first;
    tree[n].second = tree[l].second + tree[r].second;
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return {0, 0}; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return {L.first + R.first, L.second + R.second}; 
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  s = '.' + s;
  t = '.' + t;

  st.build(1, 1, n);
  while (m--) {
    int l, r; cin >> l >> r;
    st.upd(1, 1, n, l, r, 1);
  }

  for (int i = 1; i <= n; i++) {
    if (st.query(1, 1, n, i, i).second == 0) s[i] = t[i];
  }

  cout << s.substr(1) << '\n';

  return 0;
}