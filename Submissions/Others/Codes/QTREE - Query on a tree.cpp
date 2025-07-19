#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

const int N = 10000 + 9, LOG = 20, inf = 1e9;
vector<int> g[N];
int par[N][LOG], depth[N], sz[N];
int disc[N], finish[N], timer, head[N];
int n;

struct ST {
  int tree[4 * N];
  void build(int n, int  b, int e) {
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = max(tree[l], tree[r]);
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
    tree[n] = max(tree[l], tree[r]);
  }
  int query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return -inf;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return max(L, R);
  }
} st;

void dfs(int u, int p = 0) {
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  sz[u] = 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  if (p) g[u].erase(find(g[u].begin(), g[u].end(), p));
  for (auto &v : g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
      if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
  }
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

void dfs_hld(int u) {
  disc[u] = ++timer;
  for (auto v : g[u]) {
    head[v] = (v == g[u][0] ? head[u] : v);
    dfs_hld(v);
  }
  finish[u] = timer;
}

int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  return u;
}

int query_up(int u, int v) {
  int ans = -inf;
  while (head[u] != head[v]) {
    ans = max(ans, st.query(1, 1, n, disc[head[u]], disc[u]));
    u = par[head[u]][0];
  }
  ans = max(ans, st.query(1, 1, n, disc[v], disc[u]));
  return ans;
}

int query(int u, int v) {
  int lc = lca(u, v);
  int ans = (u == lc ? 0 : query_up(u, kth(u, depth[u] - depth[lc] - 1)));
  if (v != lc) {
    ans = max(ans, query_up(v, kth(v, depth[v] - depth[lc] - 1)));
  }
  return ans;
}

void clr(int n) {
  timer = 0;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

void solve() {
  cin >> n;
  clr(n);
  vector<array<int, 3>> edges;
  edges.push_back({0, 0, 0});
  for (int i = 2; i <= n; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.push_back({u, v, w});
  }
  dfs(1);
  head[1] = 1;
  dfs_hld(1);
  st.build(1, 1, n);

  for (int i = 1; i < edges.size(); i++) {
    auto [u, v, w] = edges[i];
    if (par[u][0] == v) {
      st.upd(1, 1, n, disc[u], w);
    }
    else {
      st.upd(1, 1, n, disc[v], w);
    }
  }

  string q;
  while (cin >> q) {
    if (q == "DONE") break;
    if (q == "QUERY") {
      int u, v; cin >> u >> v;
      if (u == v) cout << "0\n";
      else cout << query(u, v) << '\n';
    }
    else {
      int i, w; cin >> i >> w;
      auto [u, v, _] = edges[i];
      if (par[u][0] == v) {
        st.upd(1, 1, n, disc[u], w);
      }
      else {
        st.upd(1, 1, n, disc[v], w);
      }
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
