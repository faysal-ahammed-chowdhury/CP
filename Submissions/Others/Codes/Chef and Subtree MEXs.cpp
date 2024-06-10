#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9;
vector<int> g[N];

pair<ll, int> dfs(int u, int p) {
  ll score = 0;
  int member = 1;
  ll mx = 0;
  for (auto v : g[u]) {
    if (v != p) {
      pair<ll, int> tmp = dfs(v, u);
      mx = max(mx, tmp.first);
      member += tmp.second;
    }
  }
  score = mx + member;
  return {score, member};
}

void solve() {
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int p; cin >> p;
    g[p].push_back(i + 1);
    g[i + 1].push_back(p);
  }

  pair<ll, int> ans = dfs(1, 0);
  cout << ans.first << '\n';

  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}