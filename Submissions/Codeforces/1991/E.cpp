#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;
vector<int> g[N];
bool vis[N];
int col[N];
bool has_odd_cycle;

void dfs(int u, int c) {
  vis[u] = true;
  col[u] = c;
  for (auto v : g[u]) {
    if (col[v] != -1 and col[v] == c) has_odd_cycle = true;
    if (!vis[v]) {
      dfs(v, !c);
    }
  }
}

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
    vis[i] = false;
    col[i] = -1;
  }
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  has_odd_cycle = false;
  dfs(1, 0);
  if (has_odd_cycle) {
    cout << "Alice" << endl;
    for (int i = 1; i <= n; i++) {
      cout << 1 << ' ' << 2 << endl;
      int a, b; cin >> a >> b;
    }
  }
  else {
    cout << "Bob" << endl;
    vector<int> one, two;
    for (int i = 1; i <= n; i++) {
      if (!col[i]) one.push_back(i);
      else two.push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      int a, b; cin >> a >> b;
      if (a > b) swap(a, b);
      if (a == 1 and b == 2) {
        if (!one.empty()) {
          cout << one.back() << ' ' << a << endl;
          one.pop_back();
        }
        else if (!two.empty()) {
          cout << two.back() << ' ' << b << endl;
          two.pop_back();
        }
      }
      else if (a == 1 and b == 3) {
        if (!one.empty()) {
          cout << one.back() << ' ' << a << endl;
          one.pop_back();
        }
        else if (!two.empty()) {
          cout << two.back() << ' ' << b << endl;
          two.pop_back();
        }
      }
      else if (a == 2 and b == 3) {
        if (!two.empty()) {
          cout << two.back() << ' ' << a << endl;
          two.pop_back();
        }
        else if (!one.empty()) {
          cout << one.back() << ' ' << b << endl;
          one.pop_back();
        }
      }
    }
  }
}

int32_t main() {

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
