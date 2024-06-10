#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);
vector<int> dis(N, -1);
vector<int> par(N);

void bfs(int u) {
  vis[u] = true;
  dis[u] = 1;
  queue<int> q;
  q.push(u);

  while(!q.empty()) {
    int top = q.front();
    q.pop();
    for(auto v: g[top]) {
      if(!vis[v]) {
        vis[v] = true;
        q.push(v);
        dis[v] = dis[top] + 1;
        par[v] = top;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  bfs(1);

  if(dis[n] == -1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  cout << dis[n] << '\n';
  vector<int> path;
  int curr = n;
  while(curr != 0) {
    path.push_back(curr);
    curr = par[curr];
  }
  reverse(path.begin(), path.end());

  for(auto i: path) {
    cout << i << ' ';
  }
  cout << '\n';


  return 0;
}