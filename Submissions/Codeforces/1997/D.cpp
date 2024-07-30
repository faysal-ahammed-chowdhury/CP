#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e5 + 9, inf = 1e16;
int a[N], n;
vector<int> g[N];
 
int dfs(int u, int p) {
  bool leaf = true;
  int mn = inf;
  for (auto v : g[u]) {
    if (v != p) {
      leaf = false;
      mn = min(mn, dfs(v, u));
    }
  }
  if (leaf) return a[u];
  if (u == 1) return a[u] + mn;
  if (a[u] >= mn) return mn;
  int avg = (a[u] + mn) / 2;
  return avg;
}

void solve() {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int u = 2; u <= n; u++) {
    int v; cin >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cout << dfs(1, -1) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}