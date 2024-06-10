#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const long long INF = 1e18;

int n, m, P, G;
int visited[N];
int parent[N];
long long d[N], d2[N];
vector<pair<long long, int>> graph[N];

void dijkstra(int src) {
  // initially INF distance
  for (int i = 1; i <= n; i++) {
    d[i] = INF;
  }

  // src 0 distance
  d[src] = 0;

  priority_queue<pair<long long, int>> pq;
  pq.push({0, src});

  while (!pq.empty()) {
    // take the lowest unvisited distance
    pair<long long, int> top = pq.top();
    pq.pop();

    long long distance = -top.first;
    int selected_node = top.second;

    if (visited[selected_node] == 1) {
      continue;
    }

    visited[selected_node] = 1;

    // explore lowest distance node and relaxation
    for (auto adj : graph[selected_node]) {
      int adj_node = adj.first;
      int w = adj.second;
      if (d[adj_node] > distance + w) {
        d[adj_node] = distance + w;
        pq.push({ -d[adj_node], adj_node});
        parent[adj_node] = selected_node;
      }
    }
  }
}

void dijkstra2(int src) {
  // initially INF distance
  for (int i = 1; i <= n; i++) {
    d2[i] = INF;
    visited[i] = false;
  }

  // src 0 distance
  d2[src] = 0;

  priority_queue<pair<long long, int>> pq;
  pq.push({0, src});

  while (!pq.empty()) {
    // take the lowest unvisited distance
    pair<long long, int> top = pq.top();
    pq.pop();

    long long distance = -top.first;
    int selected_node = top.second;



    if (visited[selected_node] == 1) {
      continue;
    }

    if (selected_node == G) {
      continue;
    }

    visited[selected_node] = 1;

    // explore lowest distance node and relaxation
    for (auto adj : graph[selected_node]) {
      int adj_node = adj.first;
      int w = adj.second;
      if (adj_node == G) {
        continue;
      }
      if (d2[adj_node] > distance + w) {
        d2[adj_node] = distance + w;
        pq.push({ -d2[adj_node], adj_node});
        parent[adj_node] = selected_node;
      }
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  cin >> P >> G;
  while (m--) {
    int u, v, w; cin >> u >> v >> w;
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
  }

  dijkstra(P);
  dijkstra2(P);

  bool ok = false;
  for (int i = 1; i <= n; i++) {
    if (d[i] == d[G] * 2 and d2[i] != d[i]) {
      cout << i << ' ';
      ok = true;
    }
  }

  if (!ok) {
    cout << "*\n";
  }
  else {
    cout << '\n';
  }

  return 0;
}