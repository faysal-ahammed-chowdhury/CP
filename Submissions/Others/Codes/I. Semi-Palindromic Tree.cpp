#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];

char change(char c) {
  return (c == 'a' ? 'b' : 'a');
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  string ans = "";
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 1) ans += 'a';
    else ans += 'b';
  }
  if (ans[0] == 'b') {
    for (auto &c : ans) {
      c = change(c);
    }
  }

  cout << ans << '\n';

  return 0;
}