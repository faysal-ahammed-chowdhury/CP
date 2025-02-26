#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 1e5 + 9, LOG = 20;
vector<int> g[N];
int par[N][LOG], depth[N];
int n;

void dfs(int u, int p) {
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

int bfs(int u, vector<int> &dis) {
  dis.resize(n + 1);
  for(int i = 1; i <= n; i++) {
    dis[i] = -1;
  }
  dis[u] = 0;
  queue<int> q;
  q.push(u);

  while(!q.empty()) {
    int top = q.front();
    q.pop();
    for(auto v: g[top]) {
      if(dis[v] == -1) {
        dis[v] = dis[top] + 1;
        q.push(v);
      }
    }
  }

  int farthest = max_element(dis.begin() + 1, dis.end()) -  dis.begin();
  return farthest;
}

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    depth[0] = 0;
  }
}

bool ok(int node, int dis) {
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    ok &= dist(node, i) <= dis;
  }
  return ok;
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    ++u, ++v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0); // change root if needed

  vector<int> dis1(n + 5, -1), dis2(n + 5, -1);
  int s = bfs(1, dis1);
  int e = bfs(s, dis1);
  bfs(e, dis2);

  int l = 1, r = dist(s, e), ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    int node1 = kth(s, e, mid);
    int node2 = kth(e, s, mid);
    if (ok(node1, mid) or ok(node2, mid)) {
      ans = mid;
      r = mid - 1;
    }
    else l = mid + 1;
  }

  cout << ans << '\n';
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
