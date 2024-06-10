#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int N = 2e5 + 9; // change here
vector<int> g[N];
int n, m;

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  m = n - 1;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> dis1(n + 1), dis2(n + 1);
  int one_ending = bfs(1, dis1);
  int another_ending = bfs(one_ending, dis2);
  int d = dis2[another_ending];
  cout << d << '\n';

  return 0;
}

// https://cses.fi/problemset/task/1131