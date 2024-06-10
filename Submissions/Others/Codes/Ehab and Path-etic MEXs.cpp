#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
vector<pair<int, int>> edges;
map<pair<int, int>, int> mp;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int m = n - 1;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    edges.emplace_back(u, v);
    mp[{u, v}] = -1;
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() >= 3) {
      for (int j = 0; j < 3; j++) {
        if (mp.find({i, g[i][j]}) != mp.end()) {
          mp[{i, g[i][j]}] = cnt++;
        }
        else {
          mp[{g[i][j], i}] = cnt++;
        }
      }
      break;
    }
  }

  for (auto e : edges) {
    if (mp[e] == -1) {
      cout << cnt++ << '\n';
    }
    else {
      cout << mp[e] << '\n';
    }
  }

  return 0;
}