#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 10005;
vector<int> g[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = g[i].size();
    ans += (x * (x - 1)) / 2;
  }
  cout << ans << '\n';

  return 0;
}