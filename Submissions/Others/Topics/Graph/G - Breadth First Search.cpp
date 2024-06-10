#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 105;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> dis(N, -1);

void bfs(int u) {
  vis[u] = true;
  queue<int> q;
  q.push(u);
  dis[u] = 0;

  while(!q.empty()) {
    int top = q.front();
    q.pop();
    for(auto v: g[top]) {
      if(!vis[v]) {
        q.push(v);
        vis[v] = true;
        dis[v] = dis[top] + 1;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for(int i = 1; i <= n; i++) {
    int u, k; cin >> u >> k;
    while(k--) {
      int v; cin >> v;
      g[u].push_back(v);
    }
  }

  bfs(1);
  for(int u = 1; u <= n; u++) {
    cout << u << ' ' << dis[u] << '\n';
  }

  return 0;
}