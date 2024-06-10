#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9;
vector<int> g[N];
vector<bool> vis(N, false);

int dfs(int u) {
  vis[u] = true;
  int ans = 1;
  for (auto v : g[u]) {
    if (!vis[v] and v != 1) {
      ans += dfs(v);
    }
  }
  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int m = n - 1;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = 1;
  vector<int> vec;
  for (auto v : g[1]) {
    vec.push_back(dfs(v));
  }
  sort(vec.begin(), vec.end());
  for (int i = 0; i < vec.size() - 1; i++) {
    ans += vec[i];
  }
  cout << ans << '\n';

  return 0;
}