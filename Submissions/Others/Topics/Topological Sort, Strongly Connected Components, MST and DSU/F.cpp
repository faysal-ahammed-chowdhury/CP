#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, inf = 1e9;
vector<int> g[N];
vector<int> indeg(N, 0);
int ans[N], child[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    indeg[v]++;
  }

  queue<int> q;
  for (int i = 1; i <= n; i++) {
    ans[i] = -1;
    child[i] = -1;
    if (indeg[i] == 0) {
      q.push(i);
    }
  }

  vector<int> order;
  while (!q.empty()) {
    int top = q.front();
    q.pop();
    order.push_back(top);
    for (auto v : g[top]) {
      indeg[v]--;
      if (indeg[v] == 0) {
        q.push(v);
      }
    }
  }

  if ((int)order.size() == n) {
    reverse(order.begin(), order.end());
    ans[n] = 1;
    for (auto u : order) {
      for (auto v : g[u]) {
        if (ans[v] != -1) {
          if (ans[u] <= 1 + ans[v]) {
            child[u] = v;
            ans[u] = 1 + ans[v];
          }
        }
      }
    }

    if (ans[1] != -1) {
      cout << ans[1] << '\n';
      int cur = 1, cnt = 0;
      while (cur != -1) {
        cnt++;
        cout << cur << ' ';
        cur = child[cur];
      }
      cout << '\n';
      assert(cnt == ans[1]);
    }
    else {
      cout << "IMPOSSIBLE\n";
    }
  }
  else {
    cout << "IMPOSSIBLE\n";
  }

  return 0;
}