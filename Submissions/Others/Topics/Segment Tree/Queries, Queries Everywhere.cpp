#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9; 
const ll inf = 1e18; 
int a[N];

struct ST {
  array<ll, 2> tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = {a[b], a[b]}; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n][0] = tree[l][0] + tree[r][0]; 
    tree[n][1] = min(tree[l][1], tree[r][1]); 
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = {x, x};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n][0] = tree[l][0] + tree[r][0]; 
    tree[n][1] = min(tree[l][1], tree[r][1]); 
  }
  array<ll, 2> query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return {0, inf}; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    array<ll, 2> L = query(l, b, mid, i, j);
    array<ll, 2> R = query(r, mid + 1, e, i, j);
    return {L[0] + R[0], min(L[1], R[1])}; 
  }
} st;

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st.build(1, 1, n);
  while (m--) {
    int type; cin >> type;
    if (type == 1) {
      int i, x; cin >> i >> x;
      st.upd(1, 1, n, i, x);
    }
    else {
      int l, r; cin >> l >> r;
      auto tmp = st.query(1, 1, n, l, r);
      cout << tmp[0] - tmp[1] << '\n'; 
    }
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