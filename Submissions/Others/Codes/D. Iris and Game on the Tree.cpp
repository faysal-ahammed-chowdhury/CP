#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> g[N];
string s;
int leaf0, leaf1, leafQ;

void dfs(int u, int p) {
  bool leaf = true;
  for (auto v : g[u]) {
    if (v != p) {
      leaf = false;
      dfs(v, u);
    }
  }
  if (leaf) {
    leaf0 += s[u] == '0';
    leaf1 += s[u] == '1';
    leafQ += s[u] == '?';
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }

  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  cin >> s;
  s = '.' + s;
  int tot = 0;
  for (auto c : s) {
    tot += c == '?';
  }
  leaf0 = 0, leaf1 = 0, leafQ = 0;
  dfs(1, -1);
  int unimportant = tot - leaf0 - leaf1 - leafQ - (s[1] == '?');
  if (s[1] == '?') {
    if (leaf0 == leaf1) {
      if (unimportant & 1) {
        int ans = leaf0;
        ans += (leafQ + 1) / 2;
        cout << ans << '\n';
      }
      else {
        int ans = leaf0;
        ans += leafQ / 2;
        cout << ans << '\n';
      }
    }
    else {
      int ans = max(leaf0, leaf1);
      ans += leafQ / 2;
      cout << ans << '\n';
    }
  }
  else {
    int ans = (s[1] == '0' ? leaf1 : leaf0);
    ans += (leafQ + 1) / 2;
    cout << ans << '\n';
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