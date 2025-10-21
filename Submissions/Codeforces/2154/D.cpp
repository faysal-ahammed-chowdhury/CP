#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, inf = 1e9;
vector<int> g[N];
vector<int> even, odd;
int par[N], level[N];
bool path_node[N];
vector<int> path;

bool cmp(int a, int b) {
  return level[a] > level[b]; 
}

void clr(int n) {
  path.clear();
  even.clear();
  odd.clear();
  for (int i = 1; i <= n; i++) {
    path_node[i] = false;
    g[i].clear();
  }
}

void dfs(int u, int p, int lvl) {
  level[u] = lvl;
  par[u] = p;
  if (lvl % 2 == 0) even.push_back(u);
  else odd.push_back(u);
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u, lvl + 1);
    }
  }
}

void solve() {
  int n; cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs(1, 0, 0);
  sort(odd.begin(), odd.end(), cmp);
  sort(even.begin(), even.end(), cmp);

  int cur = n;
  while (cur != 0) {
    path.push_back(cur);
    path_node[cur] = true;
    cur = par[cur];
  }
  reverse(path.begin(), path.end());

  vector<pair<int, int>> ans;
  int time = 0, idx1 = 0, idx2 = 0;
  while (true) {
    if (time % 2 == 0) {
      int mx_even_lvl = (idx1 < even.size()) ? level[even[idx1]] : 0;
      if (idx1 < even.size() and path_node[even[idx1]]) {
        idx1++;
        continue;
      }
      int mx_odd_lvl = (idx2 < odd.size()) ? level[odd[idx2]] : inf;
      if (idx2 < odd.size() and path_node[odd[idx2]]) {
        idx2++;
        continue;
      }
      if (idx2 < odd.size() and mx_odd_lvl > mx_even_lvl) {
        int odd_node = odd[idx2];
        ans.push_back({2, odd_node});
        ans.push_back({1, 1});
        time++;
        idx2++;
      }
      else {
        ans.push_back({1, 1});
        time++;
      }
    }
    else {
      int mx_even_lvl = (idx1 < even.size()) ? level[even[idx1]] : inf;
      if (idx1 < even.size() and path_node[even[idx1]]) {
        idx1++;
        continue;
      }
      int mx_odd_lvl = (idx2 < odd.size()) ? level[odd[idx2]] : 0;
      if (idx2 < odd.size() and path_node[odd[idx2]]) {
        idx2++;
        continue;
      }
      if (idx1 < even.size() and mx_even_lvl > mx_odd_lvl) {
        int even_node = even[idx1];
        ans.push_back({2, even_node});
        ans.push_back({1, 1});
        time++;
        idx1++;
      }
      else {
        ans.push_back({1, 1});
        time++;
      }
    }

    if (idx1 >= even.size() and idx2 >= odd.size()) break;
  }

  int idx = 0;
  while (idx < path.size()) {
    int x = path[idx];
    if (x == n) break;
    int lvl = level[x];
    if (time % 2 == lvl % 2) {
      ans.push_back({1, 1});
      time++;
    }
    else {
      ans.push_back({2, x});
      ans.push_back({1, 1});
      time++;
      idx++;
    }
  }

  assert(ans.size() <= 3 * n);
  cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    if (x == 1) cout << x << '\n';
    else cout << x << ' ' << y << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}