#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9;
int n, a[N];
vector<int> g[N];
int ans_normal[N], extra[N], sub_sum[N];
int lvl[N];

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    extra[i] = 0;
    sub_sum[i] = 0;
    ans_normal[i] = 0;
    lvl[i] = 0;
  }
}

void dfs(int u, int p) {
  ans_normal[u] = 0;
  sub_sum[u] = a[u];
  lvl[u] = lvl[p] + 1;
  // cout << u << ' ' << lvl[u] << '\n';
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    ans_normal[u] += ans_normal[v];
    sub_sum[u] += sub_sum[v];
  }
  ans_normal[u] += sub_sum[u] - a[u];
  // cout << u << ' ' << ans_normal[u] << ' ' << sub_sum[u] << '\n';
}

array<int, 5> dfs2(int u, int p) {
  array<int, 5> mx = { -2, -2, -2, -2, -2}, sec_mx = { -2, -2, -2, -2, -2};
  int mx_lvl = lvl[u];
  int here = 0;
  for (auto v : g[u]) {
    if (v == p) continue;
    auto cur = dfs2(v, u);
    here = max(here, cur[3]);
    mx_lvl = max(mx_lvl, cur[4]);
    if (cur >= mx) {
      sec_mx = mx;
      mx = cur;
    }
    else if (cur >= sec_mx) {
      sec_mx = cur;
    }
  }

  int add = 0;
  if (mx[0] >= 0) {
    for (auto v : g[u]) {
      if (v == p) continue;
      if (mx[2] == v) {
        add = max(add, (sec_mx[0] - lvl[v] + 1) * sub_sum[v]);
      }
      else {
        add = max(add, (mx[0] - lvl[v] + 1) * sub_sum[v]);
        // if (u == 1) {
        //   cout << mx[0] << ' ' << sec_mx[0] << '\n';
        // }
      }
    }
  }
  extra[u] = max(here, add);

  return {mx_lvl, -sub_sum[u], u, extra[u], mx_lvl};
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  lvl[0] = -1;
  dfs(1, 0);
  dfs2(1, 0);

  for (int i = 1; i <= n; i++) {
    cout << ans_normal[i] + extra[i] << ' ';
  }
  cout << '\n';
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