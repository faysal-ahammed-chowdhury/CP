#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
vector<int> g[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int d[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> d[i];
  }
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0) {
      bool yes = true;
      for (auto v : g[i]) {
        yes &= d[v] == 1;
      }
      if (yes) {
        cout << i << '\n';
        return 0;
      }
    }
  }
  assert(false);

  return 0;
}