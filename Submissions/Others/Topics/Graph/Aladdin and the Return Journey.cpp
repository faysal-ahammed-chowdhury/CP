#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 30005, LOG = 20;
vector<int> g[N];
int par[N][LOG], depth[N], disc[N], finish[N], timer, a[N + N], val[N];

void dfs(int u, int p) {
  disc[u] = ++timer;
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = ++timer;
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int k = depth[u] - depth[v];
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  if (u == v) return u;
  for (int i = LOG - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

struct ST {
  int tree[4 * (N + N)];
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
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R);
  }
} st;

int cs;
void solve() {
  int n; cin >> n;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }

  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    ++u, ++v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  timer = 0;
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    a[disc[i]] = val[i];
    a[finish[i]] = -val[i];
  }
  st.build(1, 1, n + n);

  cout << "Case " << ++cs << ":\n";
  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 0) {
      int u, v; cin >> u >> v;
      ++u, ++v;
      int l = lca(u, v);
      int ans = st.query(1, 1, n + n, disc[l], disc[u]);
      ans += st.query(1, 1, n + n, disc[l], disc[v]);
      ans -= st.query(1, 1, n + n, disc[l], disc[l]);
      cout << ans << '\n';
    }
    else {
      int u, k; cin >> u >> k;
      ++u;
      st.upd(1, 1, n + n, disc[u], k);
      st.upd(1, 1, n + n, finish[u], -k);
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
