#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, mod = 1e9 + 7;
vector<int> g[N];
vector<int> indeg(N, 0);
int ans[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while(m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    indeg[v]++;
  }

  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(indeg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> order;
  while(!q.empty()) {
    int top = q.front();
    q.pop();
    order.push_back(top);
    for(auto v: g[top]) {
      indeg[v]--;
      if(indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  reverse(order.begin(), order.end());

  ans[n] = 1;
  for (auto u : order) {
    for (auto v : g[u]) {
      ans[u] += ans[v];
      ans[u] %= mod;
    }
  }

  cout << ans[1] << '\n';

  return 0;
}