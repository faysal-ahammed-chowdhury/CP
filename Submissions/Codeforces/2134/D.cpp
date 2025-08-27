#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int, int> pii;

const int N = 2e5 + 9, inf = 1e18;
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

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  bool ok = true;
  for (int i = 1; i <= n; i++) {
    ok &= g[i].size() <= 2;
  }

  if (ok) {
    cout << -1 << '\n';
    return;
  }

  vector<int> dis1(n + 1), dis2(n + 1);
  int node1 = bfs(1, dis1);
  int node2 = bfs(node1, dis1);
  bfs(node2, dis2);

  vector<int> vec;
  int cur = node1;
  while (cur != node2) {
    vec.push_back(cur);
    int go = cur;
    for (auto v : g[cur]) {
      if (dis2[v] <= dis2[go]) {
        go = v;
      }
    }
    cur = go;
  }
  vec.push_back(cur);

  // for (auto x : vec) {
  //   cout << x << ' ';
  // }
  // cout << '\n';

  int half = vec.size() / 2;

  for (int i = 1; i + 1 < (int)vec.size(); i++) {
    int u = vec[i];
    if (g[u].size() > 2) {
      int node = -1;
      for (auto v : g[u]) {
        if (v == vec[i - 1] or v == vec[i + 1]) continue;
        node = v;
        break;
      }
      assert(node != -1);
      if (i >= half) {
        cout << vec[i - 1] << ' ' << u << ' ' << node << '\n';
        return;
      }
      else {
        cout << vec[i + 1] << ' ' << u << ' ' << node << '\n';
        return;
      }
    }
  }
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