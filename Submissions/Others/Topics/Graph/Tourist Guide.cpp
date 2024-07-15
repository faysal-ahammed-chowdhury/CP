#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 9;
vector<int> g[N];
int disc[N], low[N], timer;
vector<bool> vis(N, false), is_ap(N, false);

void find_ap(int u, int p) {
  disc[u] = low[u] = ++timer;
  vis[u] = true;
  int children_cnt = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    if (vis[v]) low[u] = min(low[u], disc[v]);
    else {
      find_ap(v, u);
      low[u] = min(low[u], low[v]);
      if (disc[u] <= low[v] and p != -1) is_ap[u] = true;
      children_cnt++;
    }
  }
  if (p == -1 and children_cnt > 1) is_ap[u] = true;
}

int cs;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, first = true;
  while (cin >> n and n) {
    if (!first) cout << '\n';
    first = false;
    map<string, int> mp1;
    map<int, string> mp2;
    for (int i = 1; i <= n; i++) {
      string s; cin >> s;
      mp1[s] = i;
      mp2[i] = s;
    }
    int m; cin >> m; while (m--) {
      string u, v; cin >> u >> v;
      g[mp1[u]].push_back(mp1[v]);
      g[mp1[v]].push_back(mp1[u]);
    }
    for (int u = 1; u <= n; u++) {
      if (!vis[u]) {
        timer = 0;
        find_ap(u, -1);
      }
    }
    vector<string> ans;
    for (int u = 1; u <= n; u++) if (is_ap[u]) ans.push_back(mp2[u]);
      sort(ans.begin(), ans.end());
    cout << "City map #" << ++cs << ": " << ans.size() << " camera(s) found" << '\n';
    for (auto s : ans) cout << s << '\n';
    for (int i = 0; i <= n; i++) {
      g[i].clear();
      vis[i] = false;
      is_ap[i] = false;
      low[i] = 0;
      disc[i] = 0;
    }
  }

  return 0;
}