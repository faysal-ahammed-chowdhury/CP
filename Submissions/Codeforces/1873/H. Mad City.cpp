#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

const int N = 2e5 + 9;
vector<int> g[N];
int vis[N], par[N];
int level1[N], level2[N];
int cycle_start, cycle_end;

void dfs(int u, int come) {
  vis[u] = 1;
  for (auto v: g[u]) {
    if (!vis[v]) {
      par[v] = u;
      dfs(v, u);
    }
    else if(vis[v] == 1 and v != come) {
      cycle_start = v;
      cycle_end = u;
    }
  }
  vis[u] = 2;
}

void bfs1(int u) {
  level1[u] = 0;
  queue<int> q;
  q.push(u);
  vis[u] = true;
  while(!q.empty()) {
    int top = q.front(); q.pop();
    for(auto v: g[top]) {
      if(!vis[v]) {
        q.push(v);
        vis[v] = true;
        level1[v] = level1[top] + 1;
      }
    }
  }
}

void bfs2(int u) {
  level2[u] = 0;
  queue<int> q;
  q.push(u);
  vis[u] = true;
  while(!q.empty()) {
    int top = q.front(); q.pop();
    for(auto v: g[top]) {
      if(!vis[v]) {
        q.push(v);
        vis[v] = true;
        level2[v] = level2[top] + 1;
      }
    }
  }
}

void solve() {
  int n, a, b; cin >> n >> a >> b;
  
  for(int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = 0;
    par[i] = 0;
    level1[i] = 0;
    level2[i] = 0;
  }
  
  for(int i = 1; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  vector<int> cycle;
  int curr = cycle_end;
  while(curr != cycle_start) {
    cycle.push_back(curr);
    curr = par[curr];
  }
  cycle.push_back(curr);

  for(int i = 1; i <= n; i++) vis[i] = 0;
  bfs1(a);
  for(int i = 1; i <= n; i++) vis[i] = 0;
  bfs2(b);

  for(auto v: cycle) {
    if(level2[v] < level1[v]) {
      cout << "Yes\n";
      return;
    }
  }

  cout << "No\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}