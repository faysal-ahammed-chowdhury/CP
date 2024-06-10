#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> g[N];
int n;

int bfs(int u, vector<int> &dis) { // return farthest node
  for(int i = 1; i <= n; i++) {
    dis[i] = -1;
  }
  dis[u] = 0;
  queue<int> q;
  q.push(u);

  while(!q.empty()) {
    int top = q.front();
    q.pop();

    for(auto v : g[top]) {
      if(dis[v] == -1) {
        dis[v] = dis[top] + 1;
        q.push(v);
      }
    }
  }

  int farthest_node = max_element(dis.begin() + 1, dis.end()) - dis.begin();
  return farthest_node;
}

int f(int b, vector<int> &dis, int cnt) {
  int u = b;
  for (int i = 1; i <= cnt; i++) {
    for (auto v : g[u]) {
      if (dis[v] < dis[u]) {
        u = v;
        break;
      }
    }
  }
  return u;
}

void solve() {
  int a, b; cin >> n >> a >> b;
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> dis(n + 1);
  bfs(a, dis);
  int d = dis[b], initial_go_dist = (d + 1) / 2;
  int node = f(b, dis, initial_go_dist);
  int largest_node_distance = dis[bfs(node, dis)];
  int ans = initial_go_dist + (2 * (n - 1)) - largest_node_distance;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}