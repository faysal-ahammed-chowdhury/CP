#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

const int N = 1e5 + 9, LG = 20;
const ll inf = 1e18;

struct node {
  ll tot_sum;
  ll prefix_max, suffix_max;
  ll max_subarray_sum;
};

node merge(node l, node r) {
  if (l.tot_sum == -inf) return r;
  if (r.tot_sum == -inf) return l;
  node ans;
  ans.max_subarray_sum = max(l.max_subarray_sum, r.max_subarray_sum);
  ans.max_subarray_sum = max(ans.max_subarray_sum, l.suffix_max + r.prefix_max);
  ans.tot_sum = l.tot_sum + r.tot_sum;
  ans.prefix_max = l.prefix_max;
  if (l.tot_sum + r.prefix_max >= l.prefix_max) {
    ans.prefix_max = l.tot_sum + r.prefix_max;
  }
  ans.suffix_max = r.suffix_max;
  if (r.tot_sum + l.suffix_max >= r.suffix_max) {
    ans.suffix_max = r.tot_sum + l.suffix_max;
  }
  return ans;
}

struct ST {
  node tree[4 * N];
  ll lazy[4 * N];
  void push(int n, int b, int e) {
    if (lazy[n] == -inf) return;
    if (lazy[n] >= 0) {
      ll x = 1ll * lazy[n] * (e - b + 1);
      tree[n] = {x, x, x, x};
    }
    else {
      ll x = lazy[n];
      tree[n] = {1ll * lazy[n] * (e - b + 1), x, x, x};
    }
    if (b != e) {
      int l = n << 1, r = l + 1;
      lazy[l] = lazy[n];
      lazy[r] = lazy[n];
    }
    lazy[n] = -inf;
  }
  void build(int n, int b, int e) {
    lazy[n] = -inf;
    if (b == e) {
      tree[n] = {0, 0, 0, 0};
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = merge(tree[l], tree[r]);
  }
  void upd(int n, int b, int e, int i, int j, int x) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy[n] = x;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x);
    upd(r, mid + 1, e, i, j, x);
    tree[n] = merge(tree[l], tree[r]);
  }
  node query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return { -inf, -inf, -inf, -inf};
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
  }
} t;

vector<int> g[N];
int par[N][LG + 1], dep[N], sz[N];
void dfs(int u, int p = 0) {
  par[u][0] = p;
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (int i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
  if (p) g[u].erase(find(g[u].begin(), g[u].end(), p));
  for (auto &v : g[u]) if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
      if (sz[v] > sz[g[u][0]]) swap(v, g[u][0]);
    }
}
int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
  if (u == v) return u;
  for (int k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
  return par[u][0];
}
int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
  return u;
}
int T, head[N], st[N], en[N];
void dfs_hld(int u) {
  st[u] = ++T;
  for (auto v : g[u]) {
    head[v] = (v == g[u][0] ? head[u] : v);
    dfs_hld(v);
  }
  en[u] = T;
}

int n;
node query_up(int u, int v) {
  node ans = { -inf, -inf, -inf, -inf};
  while (head[u] != head[v]) {
    auto tmp = t.query(1, 1, n, st[head[u]], st[u]);
    ans = merge(tmp, ans);
    u = par[head[u]][0];
  }
  auto tmp = t.query(1, 1, n, st[v], st[u]);
  ans = merge(tmp, ans);
  return ans;
}
int query(int u, int v) {
  int l = lca(u, v);
  node ans = query_up(u, l);
  swap(ans.suffix_max, ans.prefix_max);
  if (v != l) {
    auto tmp = query_up(v, kth(v, dep[v] - dep[l] - 1));
    ans = merge(ans, tmp);
  }
  return ans.max_subarray_sum;
}
void upd_up(int u, int v, int c) {
  while (head[u] != head[v]) {
    t.upd(1, 1, n, st[head[u]], st[u], c);
    u = par[head[u]][0];
  }
  t.upd(1, 1, n, st[v], st[u], c);
}
void upd(int u, int v, int c) {
  int l = lca(u, v);
  upd_up(u, l, c);
  if (v != l) upd_up(v, kth(v, dep[v] - dep[l] - 1), c);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  int val[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  head[1] = 1;
  dfs_hld(1);
  t.build(1, 1, n);
  for (int i = 1; i <= n; i++) {
    t.upd(1, 1, n, st[i], st[i], val[i]);
  }

  // cout << head[1] << '\n';
  // cout << head[2] << '\n';
  // cout << head[3] << '\n';
  // cout << head[4] << '\n';
  // cout << head[5] << '\n';
  // cout << head[6] << '\n';

  int q; cin >> q;
  while (q--) {
    int type; cin >> type;
    if (type == 1) {
      int u, v; cin >> u >> v;
      cout << max(0ll, query(u, v)) << '\n';
    }
    else {
      int u, v, c; cin >> u >> v >> c;
      upd(u, v, c);
    }
  }

  return 0;
}