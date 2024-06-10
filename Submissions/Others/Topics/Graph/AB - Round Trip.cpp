#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<int> par(N, -1);
vector<int> vis(N, 0);
int cycle_start, cycle_end;

void dfs(int u) {
  vis[u] = 1;
  for (auto v: g[u]) {
    if (vis[v] == 0) {
      par[v] = u;
      dfs(v);
    }
    else if(vis[v] == 1 and v != par[u]) {
      cycle_end = u;
      cycle_start = v;
    }
  }
  vis[u] = 2;
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

  cycle_start = -1, cycle_end = -1;
  for(int i = 1; i <= n; i++) {
    if(!vis[i]) {
      dfs(i);
    }
  }

  if(cycle_start == -1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  vector<int> v;
  int curr = cycle_end;
  while(curr != cycle_start) {
    v.push_back(curr);
    curr = par[curr];
  }
  v.push_back(cycle_start);
  reverse(v.begin(), v.end());
  cout << (int) v.size() + 1 << '\n';
  for(auto i: v) {
    cout << i << ' ';
  }
  cout << v.front() << '\n';

  return 0;
}