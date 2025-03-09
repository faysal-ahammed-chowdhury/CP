#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }

const int N = 1e5 + 9, LOG = 20;
const ll inf = 1e18;
vector<int> g[N];
int par[N][LOG], depth[N], sz[N];
int disc[N], finish[N], timer, head[N];
int n;

struct ST {
  ll tree[4 * N], lazy[4 * N];
  void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    tree[n] += lazy[n];
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
    tree[n] = max(tree[l], tree[r]);
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
    tree[n] = max(tree[l], tree[r]);
  }
  ll query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(b > j || e < i) return -inf; 
    if(b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    ll L = query(l, b, mid, i, j);
    ll R = query(r, mid + 1, e, i, j);
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

ll query_up(int u, int v) {
  ll ans = -inf; 
  while (head[u] != head[v]) {
    ans = max(ans, st.query(1, 1, n, disc[head[u]], disc[u]));
    u = par[head[u]][0];
  }
  ans = max(ans, st.query(1, 1, n, disc[v], disc[u]));
  return ans;
}

ll query(int u, int v) {
  int lc = lca(u, v);
  ll ans = query_up(u, lc);
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
  
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  head[1] = 1;
  dfs_hld(1);
  st.build(1, 1, n);
  
  int q; cin >> q;
  while (q--) {
    string s; cin >> s;
    if (s == "add") {
      int u; ll x; cin >> u >> x;
      st.upd(1, 1, n, disc[u], finish[u], x);
    }
    else {
      int u, v; cin >> u >> v;
      cout << query(u, v) << '\n';
    }
  }

  return 0;
}
