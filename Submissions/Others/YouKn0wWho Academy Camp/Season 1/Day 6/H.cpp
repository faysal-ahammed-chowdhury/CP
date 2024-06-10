#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
vector<int> par(N, -1);
vector<int> col(N, 0);
vector<bool> vis(N, false);
int cycle_start, cycle_end;
set<int> cycle;

void find_cycle(int u) {
  col[u] = 1;
  for (auto v: g[u]) {
    if (col[v] == 0) {
      par[v] = u;
      find_cycle(v);
    }
    else if(col[v] == 1 and v != par[u]) {
      cycle_end = u;
      cycle_start = v;
    }
  }
  col[u] = 2;
}

map<int, int> mp;

void dfs(int u, int p) {
  mp[u] = p;
  vis[u] = true;
  for (auto v: g[u]) {
    if (!vis[v] and cycle.find(v) == cycle.end()) {
      dfs(v, p);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n;
  m = n;
  for(int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  find_cycle(1);
  int cur = cycle_end;
  while (cur != cycle_start) {
    cycle.insert(cur);
    cur = par[cur];
  }
  cycle.insert(cur);

  for (auto x : cycle) {
    dfs(x, x);
  }

  int q; cin >> q;
  while (q--) {
    int u, v; cin >> u >> v;
    if (mp.find(u) != mp.end() and mp.find(v) != mp.end() and mp[u] == mp[v]) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }

  return 0;
}