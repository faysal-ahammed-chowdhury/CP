#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9, inf = 1e9;
vector<int> g[N];
int n, m;
int head_part_1, head_part_2, tail;
int dis_from_tail[N], dis_from_head_part_1[N], dis_from_head_part_2[N];
bool vis[N];

void bfs(int u) {
  queue<int> q;
  q.push(u);
  vis[u] = true;
  dis_from_tail[u] = 0;
  while (!q.empty()) {
    int top = q.front(); q.pop();
    for (auto v : g[top]) {
      if (!vis[v]) {
        q.push(v);
        vis[v] = true;
        dis_from_tail[v] = dis_from_tail[top] + 1;
      }
    }
  }
}

void bfs2(int u) {
  queue<int> q;
  q.push(u);
  vis[u] = true;
  dis_from_head_part_1[u] = 0;
  while (!q.empty()) {
    int top = q.front(); q.pop();
    if (top == tail) continue;
    for (auto v : g[top]) {
      if (v == head_part_2) continue;
      if (!vis[v]) {
        q.push(v);
        vis[v] = true;
        dis_from_head_part_1[v] = dis_from_head_part_1[top] + 1;
      }
    }
  }
}

void bfs3(int u) {
  queue<int> q;
  q.push(u);
  vis[u] = true;
  dis_from_head_part_2[u] = 0;
  while (!q.empty()) {
    int top = q.front(); q.pop();
    if (top == tail) continue;
    for (auto v : g[top]) {
      if (v == head_part_1) continue;
      if (!vis[v]) {
        q.push(v);
        vis[v] = true;
        dis_from_head_part_2[v] = dis_from_head_part_2[top] + 1;
      }
    }
  }
}

int cnt_body;
void dfs_body_1(int u) {
  cnt_body++;
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v] and dis_from_head_part_1[v] < dis_from_head_part_1[u]) {
      dfs_body_1(v);
    }
  }
}

void dfs_body_2(int u) {
  if (u != tail) cnt_body++;
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v] and dis_from_head_part_2[v] < dis_from_head_part_2[u]) {
      dfs_body_2(v);
    }
  }
}

int cnt_tail;
void dfs_tail(int u) {
  cnt_tail++;
  vis[u] = true;
  for (auto v : g[u]) {
    if (!vis[v]) {
      dfs_tail(v);
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  m = n + 2;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  head_part_1 = head_part_2 = tail = -1;
  for (int i = 1; i <= n; i++) {
    if (g[i].size() == 4) tail = i;
    else if (g[i].size() == 3) {
      if (head_part_1 == -1) head_part_1 = i;
      else head_part_2 = i;
    }
    dis_from_tail[i] = inf;
    dis_from_head_part_1[i] = inf;
    dis_from_head_part_2[i] = inf;
  }

  bfs(tail);
  memset(vis, false, sizeof vis);
  bfs2(head_part_1);
  memset(vis, false, sizeof vis);
  bfs3(head_part_2);
  memset(vis, false, sizeof vis);
  dfs_body_1(tail);
  dfs_body_2(tail);
  dfs_tail(tail);

  int cnt_head = n - (cnt_body + cnt_tail - 1) + 2;

  cout << cnt_head << ' ' << cnt_body << ' ' << cnt_tail << '\n';

  return 0;
}