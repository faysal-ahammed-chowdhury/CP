#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, mod = 1e9 + 7;
vector<int> g[N];
vector<bool> vis(N, false);
int cnt;

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

void dfs(int u) {
  cnt++;
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  int m = n - 1;
  while (m--) {
    int u, v, c; cin >> u >> v >> c;
    if (c == 0) {
      g[u].push_back(v);
      g[v].push_back(u);
    }
  }

  int ans = power(n, k, mod);
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) {
      cnt = 0;
      dfs(u);
      ans -= power(cnt, k, mod);
      if (ans < 0) ans += mod;
    }
  }

  cout << ans << '\n';

  return 0;
}