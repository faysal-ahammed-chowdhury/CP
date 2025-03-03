#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9; 
int a[N], inf = 1e9;

struct ST {
  pair<int, int> tree[4 * N];
  pair<int, int> merge(pair<int, int> l, pair<int, int> r) {
    if (l.first > r.first) return l;
    if (l.first < r.first) return r;
    l.second += r.second;
    return l;
  }
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {a[b], 1};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = {x, 1};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {-inf, 0};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return merge(L, R); 
  }
} st;

int cs;
void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  } 
  st.build(1, 1, n);
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int l, r; cin >> l >> r;
    l++, r++;
    cout << st.query(1, 1, n, l, r).second << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}