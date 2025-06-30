#include <bits/stdc++.h>
using namespace std;

const int N = 3000 + 9;
vector<int> g[N];
vector<int> par(N, -1);
vector<int> col(N, 0);
bool vis[N];
int cycle_start, cycle_end;
int dis[N];

void find_cycle(int u) {
  col[u] = 1;
  for (auto v : g[u]) {
    if (col[v] == 0) {
      par[v] = u;
      find_cycle(v);
    }
    else if (col[v] == 1 and v != par[u]) {
      cycle_end = u;
      cycle_start = v;
    }
  }
  col[u] = 2;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  find_cycle(1);
  int cur = cycle_end;
  queue<int> q;
  while (cur != cycle_start) {
    q.push(cur);
    vis[cur] = true;
    dis[cur] = 0;
    cur = par[cur];
  }
  q.push(cur);
  vis[cur] = true;
  dis[cur] = 0;

  while (!q.empty()) {
    int top = q.front(); q.pop();
    for (auto v : g[top]) {
      if (!vis[v]) {
        q.push(v);
        vis[v] = true;
        dis[v] = dis[top] + 1;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << dis[i] << ' ';
  }
  cout << '\n';

  return 0;
}