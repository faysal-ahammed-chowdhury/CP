#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9; 

struct ST {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == -1) return;
    tree[n] = lazy[n] * (e - b + 1);
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n]; 
      lazy[r] = lazy[n]; 
    }
    lazy[n] = -1;
  }
  void build(int n, int  b, int e) {
    lazy[n] = -1;
    if(b == e) {
      tree[n] = 0; 
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; 
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] = x; 
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = tree[l] + tree[r];
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return L + R;
  }
} st;

int cs;
void solve() {
  int n, q; cin >> n >> q;
  st.build(1, 1, n);
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int type, i, j; cin >> type >> i >> j;
    ++i, ++j;
    if (type == 1) {
      int v; cin >> v;
      st.upd(1, 1, n, i, j, v);
    }
    else {
      int sum = st.query(1, 1, n, i, j);
      int d = j - i + 1;
      int gc = __gcd(sum, d);
      sum /= gc;
      d /= gc;
      cout << sum;
      if (d == 1) cout << '\n';
      else cout << '/' << d << '\n';
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}