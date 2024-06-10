#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int, int> pii;
const int N = 1e5 + 9, inf = 1e18;
vector<pii> g[N];
int n, m, k;
vector<int> ans;

void dijkstra(int u, vector<int> &vis) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, u});
  while (!pq.empty()) {
    int d = pq.top().first;
    int selected_node = pq.top().second;
    pq.pop();
    vis[selected_node]++;
    if (vis[selected_node] > 10) continue;
    for (auto [v, w] : g[selected_node]) {
      pq.push({w + d, v});
      if (v == n) ans.push_back(w + d);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m >> k;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back({v, w});
  }
  vector<int> vis(n + 1, 0);
  dijkstra(1, vis);
  sort(ans.begin(), ans.end());
  for (int i = 0; i < k; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}