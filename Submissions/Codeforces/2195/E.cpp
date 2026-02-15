#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 3e5 + 9, mod = 1e9 + 7;
vector<int> g[N];
int sub_sz[N], lvl[N], ans[N];

void dfs(int u, int p, int level) {
  lvl[u] = level;
  sub_sz[u] = 1;
  for (auto v : g[u]) {
    // cout << u << ' ' << v << '\n';
    if (v == p) continue;
    dfs(v, u, level + 1);
    sub_sz[u] += sub_sz[v];
  }
}

void dfs2(int u, int p, int cnt) {
  cnt += (sub_sz[u] - 1) * 2;
  cnt %= mod;
  ans[u] = (cnt + lvl[u]) % mod;
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs2(v, u, cnt);
  }
}

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    sub_sz[i] = 0;
    ans[i] = 0;
    lvl[i] = 0;
    g[i].clear();
  }
}

void solve() {
  int n; cin >> n;
  clr(n);
  for (int i = 1; i <= n; i++) {
    int l, r; cin >> l >> r;
    if (l != 0) {
      g[i].push_back(l);
      g[l].push_back(i);
    }
    if (r != 0) {
      g[i].push_back(r);
      g[r].push_back(i);
    }
  }

  // for (int u = 1; u <= n; u++) {
  //   cout << u << ": ";
  //   for (auto v : g[u]) {
  //     cout << v << ' ';
  //   }
  //   cout << '\n';
  // }

  dfs(1, 0, 0);
  dfs2(1, 0, 0);

  for (int i = 1; i <= n; i++) {
    cout << (ans[i] + 1) % mod << ' ';
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