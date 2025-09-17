#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5 + 9;
int indeg[N];
vector<int> g[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    indeg[i] = 0;
  }
}

void solve() {
  int n; cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v, x, y; cin >> u >> v >> x >> y;
    if (x > y) {
      g[u].push_back(v);
      indeg[v]++;
    }
    else {
      g[v].push_back(u);
      indeg[u]++;
    }
  }

  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(indeg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> path;
  while(!q.empty()) {
    int top = q.front();
    q.pop();
    path.push_back(top);
    for(auto v: g[top]) {
      indeg[v]--;
      if(indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  int ans[n + 1];
  int cur = n;
  for (auto x : path) {
    ans[x] = cur--;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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