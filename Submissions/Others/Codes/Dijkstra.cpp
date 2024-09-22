#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, inf = 1e9; // change here
vector<array<int, 2>> g[N];
int n, m;

auto dijkstra(int s) {
  vector<int> dis(n + 1, inf);
  dis[s] = 0;
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    for (auto [v, w] : g[u]) {
      if (dis[v] > d + w) {
        dis[v] = d + w;
        pq.push({dis[v], v});
      }
    }
  }
  return dis;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  return 0;
}