#include <bits/stdc++.h>
using namespace std;

const int N = 4009;
vector<bool> visited(N, false);
vector<int> graph[N];
int n, ans;
string s;

pair<int, int> dfs(int src) {
  visited[src] = true;
  pair<int, int> p;
  if(s[src - 1] == 'B') p.first++;
  else p.second++;
  for(auto i: graph[src]) {
    if(visited[i] == false) {
      pair<int, int> p1 = dfs(i);
      p.first += p1.first;
      p.second += p1.second;
    }
  }
  if(p.first == p.second) ans++;
  return p;
}

void solve() {
  cin >> n;
  // clear old data
  for(int i = 0; i <= n; i++) {
    graph[i].clear();
    visited[i] = false;
  }
  for(int u = 2; u <= n; u++) {
    int v; cin >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  cin >> s;

  ans = 0;
  pair<int, int> p = dfs(1);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}