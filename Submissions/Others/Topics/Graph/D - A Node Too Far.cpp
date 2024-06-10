#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

map<int, vector<int>> g;

void bfs(int u, map<int, bool> &vis, map<int, int> &dis) {
  dis[u] = 0;
  vis[u] = true;
  queue<int> q;
  q.push(u);
  while(!q.empty()) {
    int top = q.front(); q.pop();
    for(auto v: g[top]) {
      if(!vis[v]) {
        vis[v] = true;
        q.push(v);
        dis[v] = dis[top] + 1;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, cs = 0; 
  while(cin >> n and n != 0) {
    g.clear();

    set<int> nodes;
    for(int i = 1; i <= n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
      nodes.insert(u);
      nodes.insert(v);
    }

    int start, ttl;
    while(cin >> start >> ttl and !(start == 0 and ttl == 0)) {
      map<int, bool> vis;
      map<int, int> dis;
      for(auto i: nodes) {
        dis[i] = inf;
        vis[i] = false;
      }
      int ans = 0;
      bfs(start, vis, dis);
      for(auto i: nodes) {
        if(dis[i] > ttl) ans++;
      }
      cout << "Case " << ++cs << ": ";
      cout << ans << " nodes not reachable from node " << start << " with TTL = " << ttl << ".\n";
    }
  }

  return 0;
}