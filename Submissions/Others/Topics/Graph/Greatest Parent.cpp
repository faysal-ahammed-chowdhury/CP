#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 2e5 + 9, LOG = 20; // change here
vector<int> g[N];
int par[N][LOG], depth[N], a[N];

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

int query(int v, int k) {
  for (int i = LOG - 1; i >= 0; i--) {
    if (par[v][i] != 0 and a[par[v][i]] >= k) {
      v = par[v][i];
    }
  }
  return v;
}

int cs;
void solve() {
  int n, q; cin >> n >> q;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    depth[0] = 0;
  }

  a[1] = 1;
  for (int i = 2; i <= n; i++) {
    int p; cin >> p >> a[i];
    ++p;
    g[i].push_back(p);
    g[p].push_back(i);
  }
  dfs(1, 0);

  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int v, k; cin >> v >> k;
    cout << query(++v, k) - 1 << '\n';
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
