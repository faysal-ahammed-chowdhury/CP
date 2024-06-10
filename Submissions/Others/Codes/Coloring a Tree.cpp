#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;
vector<int> g[N];
int n, c[N], ans;

void dfs(int u, int p) {
  if (c[u] != c[p]) ans++;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 2; i <= n; i++) {
    int p; cin >> p;
    g[i].push_back(p);
    g[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
  }
  dfs(1, 0);
  cout << ans << '\n';

  return 0;
}