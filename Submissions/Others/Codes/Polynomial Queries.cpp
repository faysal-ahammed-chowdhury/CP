#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 9; 
int a[N];

ll f(int n) {
  return (1ll * n * (n + 1)) / 2;
}

ll f(int l, int r) {
  return f(r) - f(l - 1);
}

struct ST {
  ll tree[4 * N];
  int lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n] += 1ll * lazy[n] * f(b, e); 
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[r] += lazy[n]; 
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if(b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; 
  }
  void upd(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return;
    if(b >= i && e <= j) {
      lazy[n] += 1; 
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j);
    upd(r, mid + 1, e, i, j);
    tree[n] = tree[l] + tree[r]; 
  }
  ll query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return 0; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return L + R; 
  }
} st1;

struct ST2 {
  ll tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n] += 1ll * lazy[n] * (e - b + 1); 
    if(b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[r] += lazy[n]; 
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
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
      lazy[n] += x; 
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = tree[l] + tree[r]; 
  }
  ll query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return 0; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
    return L + R; 
  }
} st2;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  st1.build(1, 1, n);
  st2.build(1, 1, n);

  while (q--) {
    int type, l, r; cin >> type >> l >> r;
    if (type == 1) {
      st1.upd(1, 1, n, l, r);
      st2.upd(1, 1, n, l, r, (l - 1));
    }
    else {
      ll ans = st1.query(1, 1, n, l, r) - st2.query(1, 1, n, l, r);
      cout << ans << '\n';
    }
  }

  return 0;
}