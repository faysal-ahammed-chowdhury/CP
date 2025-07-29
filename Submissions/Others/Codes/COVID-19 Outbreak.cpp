#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 9;
vector<pair<int, int>> g[N];
int a[N];

ll dfs(int u, int p) {
  ll ans = a[u];
  for (auto [v, w] : g[u]) {
    if (v != p) {
      ll x = dfs(v, u);
      ans += min(1ll * w, x);
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, z; cin >> n >> z;
  for (int i = 2; i <= n; i++) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  cout << dfs(z, 0) << '\n';

  return 0;
}