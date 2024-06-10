#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
const long long INF = 1e18;
int a[N];

struct ST {
  long long tree[4 * N], lazy[4 * N];
  ST() {
    memset(tree, 0, sizeof(tree));
    memset(lazy, 0, sizeof(lazy));
  }
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n] += lazy[n]; // change here
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n]; // change here
      lazy[r] += lazy[n]; // change here
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n] = a[b]; // change here
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]); // change here
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] += x; // change here
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = min(tree[l], tree[r]); // change here
  }
  long long query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return INF; // return appropriate value
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    long long L = query(l, b, mid, i, j);
    long long R = query(r, mid + 1, e, i, j);
    return min(L, R); // change here
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  st.build(1, 1, n);
  while(m--) {
    int type; cin >> type;
    if(type == 1) {
      int l, r, v; cin >> l >> r >> v;
      l++;
      st.upd(1, 1, n, l, r, v);
    }
    else {
      int i, j; cin >> i >> j;
      i++;
      cout << st.query(1, 1, n, i, j) << '\n';
    }
  }

  return 0;
}