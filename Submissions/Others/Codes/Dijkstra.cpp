#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 9, inf = 1e9; // change here
vector<pii> g[N];
int n, m;

void dijkstra(int u, vector<int> &dis) {
  for (int i = 0; i <= n; i++) {
    dis[i] = inf;
  }
  dis[u] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, u});
  while (!pq.empty()) {
    int d = pq.top().first;
    int selected_node = pq.top().second;
    pq.pop();
    for (auto [v, w] : g[selected_node]) {
      if (dis[v] > d + w) {
        dis[v] = d + w;
        pq.push({dis[v], v});
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}