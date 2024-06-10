#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);

void bfs(int u) {
  priority_queue<int, vector<int>, greater<int>> q;
  q.push(u);
  vis[u] = true;

  while(!q.empty()) {
    int top = q.top();
    q.pop();

    cout << top << ' ';

    for(auto v: g[top]) {
      if(!vis[v]) {
        q.push(v);
        vis[v] = true;
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

  for(int i = 1; i <= n; i++) {
    sort(g[i].begin(), g[i].end());
  }

  bfs(1);
  cout << '\n';

  return 0;
}