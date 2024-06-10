#include <bits/stdc++.h>
using namespace std;

const int N = 105;
vector<int> g[N];
vector<int> vis(N, false);
vector<int> ans;

void dfs(int u) {
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
  ans.push_back(u);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while(cin >> n >> m and !(n == 0 and m == 0)) {
    while(m--) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
    }

    for(int i = 1; i <= n; i++) {
      if(!vis[i]) {
        dfs(i);
      }
    }

    reverse(ans.begin(), ans.end());

    for(auto i: ans) {
      cout << i << ' ';
    }
    cout << '\n';

    ans.clear();
    for(int i = 1; i <= n; i++) {
      g[i].clear();
      vis[i] = false;
    }
  }

  return 0;
}