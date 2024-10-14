#include <bits/stdc++.h>
using namespace std;

const int N = 10;
vector<int> g[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m, p; cin >> n >> m >> p;
  while (m--) {
    int u, v; cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int mask = 0; mask < (1 << n); mask++) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (mask & (1 << i)) {
        for (auto v : g[i]) {
          if (mask & (1 << v)) {
            cnt++;
          }
        }
      }
    }
    int x = __builtin_popcount(mask);
    cnt /= 2;
    if (cnt > x + x + p) {
      cout << "ohho\n";
      bitset<10> bs(mask);
      cout << bs << ' ' << cnt << ' ' << x << '\n';
      return 0;
    }
  }

  cout << "good\n";

  return 0;
}