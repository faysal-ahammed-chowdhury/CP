#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
vector<int> g[N];
int n, a[N];
bool ok[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    ok[i] = false;
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  for (int u = 1; u <= n; u++) {
    map<int, int> mp;
    for (auto v : g[u]) {
      if (a[u] == a[v]) ok[a[u]] = true;
      mp[a[v]]++;
    }
    for (auto [x, cnt] : mp) {
      if (cnt > 1) ok[x] = true;
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ok[i];
  }
  cout << '\n';
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