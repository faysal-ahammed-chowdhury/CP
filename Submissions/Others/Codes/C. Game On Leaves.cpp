#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<int> g[N];

void solve() {
  int n, x; cin >> n >> x;
  int m = n - 1;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  if (g[x].size() <= 1) {
    cout << "Ayush\n";
    return;
  }

  if (!(n & 1)) {
    cout << "Ayush\n";
  }
  else {
    cout << "Ashish\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}