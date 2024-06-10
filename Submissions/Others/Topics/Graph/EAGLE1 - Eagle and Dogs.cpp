#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9; // change here
vector<pair<int, int>> g[N];
int n, m;

int bfs(int u, vector<ll> &dis) {
  for(int i = 1; i <= n; i++) {
    dis[i] = -1;
  }
  dis[u] = 0;
  queue<int> q;
  q.push(u);

  while(!q.empty()) {
    int top = q.front();
    q.pop();

    for(auto [v, w] : g[top]) {
      if(dis[v] == -1) {
        dis[v] = dis[top] + w;
        q.push(v);
      }
    }
  }

  int farthest_node = max_element(dis.begin() + 1, dis.end()) - dis.begin();
  return farthest_node;
}

void solve() {
  cin >> n;
  m = n - 1;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
  }

  vector<ll> dis1(n + 1), dis2(n + 1);
  int one_ending = bfs(1, dis1);
  int another_ending = bfs(one_ending, dis1);
  bfs(another_ending, dis2);

  for (int i = 1; i <= n; i++) {
    cout << max(dis1[i], dis2[i]) << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
