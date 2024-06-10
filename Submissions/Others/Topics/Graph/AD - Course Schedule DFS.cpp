#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<int> vis(N, 0);
bool cycle;
vector<int> ans;

void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (vis[v] == 0) {
      dfs(v);
    }
    else if(vis[v] == 1) {
      cycle = true;
    }
  }
  vis[u] = 2;
  ans.push_back(u);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }

  cycle = false;
  for(int i = 1; i <= n; i++) {
    if(vis[i] == 0) {
      dfs(i);
    }
  }

  if(cycle) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  reverse(ans.begin(), ans.end());
  for(auto i: ans) {
    cout << i << ' ';
  }
  cout << '\n';

  return 0;
}