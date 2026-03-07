#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLR(int &N, int pos) { (N &= ~(1ll << pos)); }

const int N = 3e5 + 9, mod = 1e9 + 7, LOG = 20, inf = 1e9;
vector<int> g[N];
int n;
int par[N][LOG], depth[N], sz[N];
int disc[N], finish[N], timer;
int val[N + N], lowest_time_from_root[N], node_in_time[N + N];

void clr(int n) {
  timer = 0;
  for (int i = 0; i <= n; i++) {
    sz[i] = 0;
    g[i].clear();
    node_in_time[i] = -1;
    lowest_time_from_root[i] = -1;
  }
}

void dfs(int u, int p, int &cur) {
  node_in_time[cur] = u;
  if (lowest_time_from_root[u] == -1) lowest_time_from_root[u] = cur;
  disc[u] = ++timer;
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  sz[u] = 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v != p) {
      cur++;
      dfs(v, u, cur);
      sz[u] += sz[v];
      cur++;
      node_in_time[cur] = u;
      if (lowest_time_from_root[u] == -1) lowest_time_from_root[u] = cur;
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

int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  return u;
}

int dist(int u, int v) {
  int l = lca(u, v);
  return (depth[u] - depth[l]) + (depth[v] - depth[l]);
}

// kth node from u to v, 0th node is u
int kth(int u, int v, int k) {
  int l = lca(u, v);
  int d = dist(u, v);
  assert(k <= d);
  if (depth[l] + k <= depth[u]) {
    return kth(u, k);
  }
  k -= depth[u] - depth[l];
  return kth(v, depth[v] - depth[l] - k);
}

bool ok(int i, int j, int k, int add) {
  i = disc[i];
  j = disc[j];
  if (i > j) swap(i, j);
  return (val[j] - val[i] + add) < k;
}

int f(int i, int j, int add) {
  i = disc[i];
  j = disc[j];
  if (i > j) swap(i, j);
  return (val[j] - val[i] + add);
}

void solve() {
  int q; cin >> n >> q;
  clr(n);
  for (int i = 1; i <= n; i++) {
    int l, r; cin >> l >> r;
    if (l != 0) {
      g[i].push_back(l);
      g[l].push_back(i);
    }
    if (r != 0) {
      g[i].push_back(r);
      g[r].push_back(i);
    }
  }

  int cnt = 0;
  dfs(1, 0, cnt);

  for (int i = 1; i <= n; i++) {
    val[disc[i]] = (sz[i] - 1) * 2 + 1;
    val[finish[i]] = -((sz[i] - 1) * 2 + 1);
  }

  for (int i = 1; i <= n + n; i++) {
    val[i] += val[i - 1];
  }

  while (q--) {
    int v, k; cin >> v >> k;

    if (k == 0) {
      cout << v << ' ';
      continue;
    }

    if (((sz[v] - 1) * 2) + 1 >= k) {
      if (k == ((sz[v] - 1) * 2 + 1)) {
        cout << par[v][0] << ' ';
        continue;
      }

      int here = lowest_time_from_root[v];
      cout << node_in_time[here + k] << ' ';
      continue;
    }

    int l = 0, r = dist(v, 1), node = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int x = kth(v, mid);
      int add = ((sz[x] - 1) * 2) + 1;
      if (ok(v, x, k, add)) {
        node = x;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }

    int add = ((sz[node] - 1) * 2) + 1;
    k -= f(v, node, add);
    node = par[node][0];

    if (k == (((sz[node] - 1) * 2) + 1)) {
      cout << par[node][0] << ' ';
      continue;
    }

    int here = lowest_time_from_root[node];
    cout << node_in_time[here + k] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}