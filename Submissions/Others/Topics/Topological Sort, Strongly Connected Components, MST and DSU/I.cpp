#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9; // change here
vector<int> g[N], gT[N], G[N];
vector<bool> vis(N, false);
vector<int> order;
int n, roots[N], indeg[N];
ll a[N], ans[N];

void dfs(int u) {
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) dfs(v);
  }
  order.push_back(u);
}

void dfs2(int u, vector<int> &component) {
  vis[u] = true;
  component.push_back(u);
  for (auto v : gT[u]) {
    if (!vis[v]) dfs2(v, component);
  }
}

void scc() {
  // get order sorted by end time
  order.clear();
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) dfs(u);
  }
  reverse(order.begin(), order.end());
  // transpose the graph
  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      gT[v].push_back(u);
    }
  }
  // get all components
  for (int i = 1; i <= n; i++) vis[i] = false;
  for (auto u : order) {
    if (!vis[u]) {
      vector<int> component;
      dfs2(u, component);
      sort(component.begin(), component.end());
      ll sum = 0;
      for (auto v : component) {
        sum += a[v];
        roots[v] = component.front();
      }
      // cout << "here: " << component.front() << ' ' << sum << '\n';
      a[component.front()] = sum;
    }
  }
  // add edges to condensation graph
  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      if (roots[u] != roots[v]) {
        G[roots[u]].push_back(roots[v]);
      }
    }
  }
}

// when you need to use condensed graph, use it carefully (Specially g->G, i->roots[i])
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ans[i] = -1;
  }

  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }

  scc();

  for (int i = 1; i <= n; i++) {
    if (i == roots[i]) {
      for (auto v : G[i]) {
        indeg[v]++;
      }
    }
  }

  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(i == roots[i] and indeg[i] == 0) {
      q.push(i);
    }
  }

  order.clear();
  while(!q.empty()) {
    int top = q.front();
    q.pop();
    order.push_back(top);
    for(auto v: G[top]) {
      indeg[v]--;
      if(indeg[v] == 0) {
        q.push(v);
      }
    }
  }
  reverse(order.begin(), order.end());

  ll mx = 0;
  for (auto u : order) {
    ans[u] = a[u];
    for (auto v : G[u]) {
      ans[u] = max(ans[u], a[u] + ans[v]);
    }
    mx = max(mx, ans[u]);
  }

  cout << mx << '\n';

  return 0;
}