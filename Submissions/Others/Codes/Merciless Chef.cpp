#include <bits/stdc++.h>
using namespace std;
#define int long long 

using ll = long long;
const int N = 1e5 + 9, inf = 1e10;
vector<int> g[N];
int n, a[N], disc[N], finish[N];
int timer, actual[N]; // actual[i] = node in index i

void dfs(int u, int p) {
  disc[u] = ++timer;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = timer;
}

struct ST {
  pair<int, int> tree[4 * N];
  int lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n].first += lazy[n];
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
      tree[n] = {a[actual[b]], b};
      // cout << b << ' ' << a[actual[b]] << '\n';
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = min(tree[l], tree[r]);
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
    tree[n] = min(tree[l], tree[r]);
  }
  pair<int, int> query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return {inf, inf};
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    pair<int, int> L = query(l, b, mid, i, j);
    pair<int, int> R = query(r, mid + 1, e, i, j);
    return min(L, R); 
  }
} st;

struct ST2 {
  int tree[4 * N];
  void build(int n, int b, int e) {
    if(b == e) {
      tree[n] = 1;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r]; 
  }
  void upd(int n, int b, int e, int i, int x) {
    if(b > i || e < i) return;
    if(b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r]; 
  }
  int query(int n, int b, int e, int i, int j) {
    if(b > j || e < i) return 0;
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R);
  }
} st2;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  a[1] = inf;
  for (int i = 1; i <= n; i++) {
    int h, p; cin >> h >> p;
    p++;
    a[i + 1] = h;
    g[p].push_back(i + 1);
    g[i + 1].push_back(p);
  }
  n++;

  dfs(1, 0);
  for (int i = 0; i <= n; i++) {
    actual[disc[i]] = i;
  }

  st.build(1, 1, n);
  st2.build(1, 1, n);

  int q; cin >> q;
  while (q--) {
    int type, node; cin >> type >> node;
    node++;
    int l = disc[node], r = finish[node];
    if (type == 1) {
      int x; cin >> x;
      st.upd(1, 1, n, l + 1, r, -x);
      while (true) {
        auto [mn, idx] = st.query(1, 1, n, l + 1, r);
        if (mn > 0) break;
        st.upd(1, 1, n, idx, idx, inf);
        st2.upd(1, 1, n, idx, 0);
      }
    }
    else {
      cout << st2.query(1, 1, n, l + 1, r) << '\n';
    }
  }

  return 0;
}