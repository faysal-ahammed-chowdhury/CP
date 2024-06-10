#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 105;
set<int> g[N];
vector<bool> vis(N, false);
int start_time[N], end_time[N];

int x = 0;
void dfs(int u) {
  start_time[u] = ++x;

  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
  end_time[u] = ++x;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    int u, k; cin >> u >> k;
    for(int j = 1; j <= k; j++) {
      int v; cin >> v;
      g[u].insert(v);
    }
  }

  for(int u = 1; u <= n; u++) {
    if(!vis[u]) {
      dfs(u);
    }
  }

  for(int u = 1; u <= n; u++) {
    cout << u << ' ' << start_time[u] << ' ' << end_time[u] << '\n';
  }

  return 0;
}