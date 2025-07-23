#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200000 + 9;
vector<int> g[N];
int n, m, a[N], disc[N], finish[N], depth[N];
int timer, actual[N]; // actual[i] = node in index i

void dfs(int u, int p) {
  disc[u] = ++timer;
  depth[u] = depth[p] + 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
  finish[u] = timer;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    actual[disc[i]] = i;
  }

  return 0;
}