#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

const int mod = 1e9 + 7;
const int N = 1e5 + 9, LOG = 20;
vector<int> g[N];
int par[N][LOG], depth[N], sz[N];
int disc[N], finish[N], timer, head[N], actual[N];
int n;

struct ST {
  int tree[4 * N], lazy[4 * N], cnt[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] += 1ll * lazy[n] * cnt[n] % mod;
    tree[n] %= mod;
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[l] %= mod;
      lazy[r] += lazy[n];
      lazy[r] %= mod;
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = 0;
      cnt[n] = depth[actual[b]];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = (tree[l] + tree[r]) % mod;
    cnt[n] = (cnt[l] + cnt[r]) % mod;
    // cout << n << ' ' << b << ' ' << e << ' ' << depth[actual[b]] << '\n';
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] += x;
      lazy[n] %= mod;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = (tree[l] + tree[r]) % mod;
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R) % mod;
  }
} st;

struct ST2 {
  int tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == 0) return;
    tree[n] += 1ll * lazy[n] * (e - b + 1) % mod;
    tree[n] %= mod;
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] += lazy[n];
      lazy[l] %= mod;
      lazy[r] += lazy[n];
      lazy[r] %= mod;
    }
    lazy[n] = 0;
  }
  void build(int n, int  b, int e) {
    lazy[n] = 0;
    if (b == e) {
      tree[n] = 0;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = (tree[l] + tree[r]) % mod;
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] += x;
      lazy[n] %= mod;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = (tree[l] + tree[r]) % mod;
  }
  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    int L = query(l, b, mid, i, j);
    int R = query(r, mid + 1, e, i, j);
    return (L + R) % mod;
  }
} st2;

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
  int ans = 0;
  while (head[u] != head[v]) {
    ans += st.query(1, 1, n, disc[head[u]], disc[u]);
    ans %= mod;
    ans += st2.query(1, 1, n, disc[head[u]], disc[u]);
    ans %= mod;
    u = par[head[u]][0];
  }
  ans += st.query(1, 1, n, disc[v], disc[u]);
  ans %= mod;
  ans += st2.query(1, 1, n, disc[v], disc[u]);
  ans %= mod;
  return ans;
}

int query(int u, int v) {
  int lc = lca(u, v);
  int ans = query_up(u, lc);
  if (v != lc) {
    ans += query_up(v, kth(v, depth[v] - depth[lc] - 1));
    ans %= mod;
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int q, root; cin >> n >> q >> root;
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(root);
  head[root] = root;
  dfs_hld(root);
  for (int i = 1; i <= n; i++) {
    actual[disc[i]] = i;
  }
  st.build(1, 1, n);
  st2.build(1, 1, n);

  while (q--) {
    char c; cin >> c;
    if (c == 'U') {
      int u, x, k; cin >> u >> x >> k;
      st.upd(1, 1, n, disc[u], finish[u], k);
      st2.upd(1, 1, n, disc[u], finish[u], x);
      int y = 1ll * depth[u] * k % mod;
      y = -y;
      y %= mod;
      if (y < 0) y += mod;
      st2.upd(1, 1, n, disc[u], finish[u], y);
    }
    else {
      int u, v; cin >> u >> v;
      cout << query(u, v) << '\n';
    }
  }

  return 0;
}
