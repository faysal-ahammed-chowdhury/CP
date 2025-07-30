#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9;
vector<int> g[N];
int n, k, lvl[N], sz[N];
vector<int> vec;

void dfs(int u, int p) {
  lvl[u] = lvl[p] + 1;
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
  vec.push_back(-(lvl[u] - sz[u]));
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0);
  sort(vec.begin(), vec.end());
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    ans += -vec[i];
  }
  cout << ans << '\n';

  return 0;
}