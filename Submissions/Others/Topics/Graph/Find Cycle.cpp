#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
vector<int> par(N, -1);
vector<int> col(N, 0);
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
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

  return 0;
}