#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9; // change here
vector<int> g[N];
int disc[N], low[N], time;
vector<bool> vis(N, false), is_ap(N, false);

void find_ap(int u, int p) { // find articulation point
  disc[u] = low[u] = ++time;
  vis[u] = true;
  int children_cnt = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (vis[v]) low[u] = min(low[u], disc[v]);
    else {
      find_ap(v, u);
      low[u] = min(low[u], low[v]);
      if (disc[u] <= low[v] and p != -1) is_ap[u] = true;
      children_cnt++;
    }
  }
  if (p == -1 and children_cnt > 1) is_ap[u] = true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}