#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

#define int long long
const int N = 2e5 + 9, M = 2e5 + 9, inf = 1e18;
vector<pair<int, pair<int, int>>> graph[N];
pair<int, int> ans[N];
vector<bool> visited(N, false);

void dfs(int src) {
  visited[src] = true;

  for(auto i: graph[src]) {
    if(visited[i.first] == false) {
      ans[i.first] = {ans[src].first + i.second.first, ans[src].second + i.second.second};
      dfs(i.first);
    }
    else if(ans[i.first].first != ans[src].first + i.second.first || ans[i.first].second != ans[src].second + i.second.second) {
      ans[i.first] ={inf, inf};
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    ans[i].first = ans[i].second = inf;
  }
  for(int i = 1; i <= m; i++) {
    int p, q, x, y; cin >> p >> q >> x >> y;
    graph[p].push_back({q, {x, y}});
    graph[q].push_back({p, {-x, -y}});
  }

  ans[1] = {0, 0};
  dfs(1);

  for(int i = 1; i <= n; i++) {
    if(ans[i].first == inf or ans[i].second == inf) {
      cout << "undecidable\n";
    }
    else {
      cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
  }

  return 0;
}