#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
vector<int> graph[N];

int dfs(int src, vector<bool> &visited, vector<int> &cnt) {
  visited[src] = true;
  bool flag = true;
  for (auto i: graph[src]) {
    if (!visited[i]) {
      flag = false;
      cnt[src] += dfs(i, visited, cnt);
    }
  }
  if(flag) {
    cnt[src]++;
  }
  return cnt[src];
}

void solve() {
  int v, e; cin >> v;
  for(int i = 0; i <= v; i++) {
    graph[i].clear();
  }
  e = v - 1;
  vector<bool> visited(v + 5, false);
  vector<int> cnt(v + 5);
  for(int i = 1; i <= e; i++) {
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  dfs(1, visited, cnt);

  int q; cin >> q;
  while(q--) {
    int x, y; cin >> x >> y;
    long long ans = 1LL * cnt[x] * cnt[y];
    cout << ans << '\n';
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}