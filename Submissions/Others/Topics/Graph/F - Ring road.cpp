#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

struct node {
  int v, w;
  bool flag;
};

const int N = 100 + 9;
vector<node> g[N];
vector<bool> vis(N, false);
int cost1, cost2;

void dfs(int u, int start, bool first, int p) {
  if(u == start and !first) return;
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v.v] or v.v == start and v.v != p) {
      if(v.flag == false) {
        cost1 += v.w;
      }
      else {
        cost2 += v.w;
      }
      dfs(v.v, start, first, u);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w, true});
    g[v].push_back({u, w, false});
  }

  dfs(1, 1, true, 0);
  cout << min(cost1, cost2) << '\n';

  return 0;
}