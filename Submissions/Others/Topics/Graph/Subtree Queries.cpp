#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int val[N], a[N], disc[N], finish[N], timer;
vector<int> g[N];

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
  long long tree[4 * (N)];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] = x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] + tree[r];
  }
  long long query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    long long L = query(l, b, mid, i, j);
    long long R = query(r, mid + 1, e, i, j);
    return (L + R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    a[disc[i]] = val[i];
  }
  st.build(1, 1, n);
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int v, x; cin >> v >> x;
      st.upd(1, 1, n, disc[v], x);
    }
    else {
      int v; cin >> v;
      cout << st.query(1, 1, n, disc[v], finish[v]) << '\n';
    }
  }

  return 0;
}