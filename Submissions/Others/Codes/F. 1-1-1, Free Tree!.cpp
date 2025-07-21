#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(pair<uint64_t, uint64_t> x) const {
    static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};

const int N = 2e5 + 9;
vector<pair<int, int>> g[N];
int n, col[N], par[N];
unordered_map<pair<int, int>, ll, custom_hash> mp, edges;
ll ans;

void dfs(int u, int p) {
  par[u] = p;
  for (auto [v, w] : g[u]) {
    if (v != p) {
      ans += (col[v] == col[u] ? 0 : w);
      mp[ {u, col[v]}] += w;
      dfs(v, u);
    }
  }
}

void clr(int n) {
  mp.clear();
  edges.clear();
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
}

void solve() {
  int q; cin >> n >> q;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> col[i];
  }
  for (int i = 2; i <= n; i++) {
    int u, v, w; cin >> u >> v >> w;
    if (u > v) swap(u, v);
    g[u].push_back({v, w});
    g[v].push_back({u, w});
    edges[ {u, v}] = w;
    edges[ {v, u}] = w;
  }

  ans = 0;
  dfs(1, 0);
  // cout << ans << '\n';

  while (q--) {
    int v, x; cin >> v >> x;
    if (col[v] != x) {
      // par
      if (v != 1) {
        // cout << "here:\n";
        // cout << par[v] << ' ' << col[v] << ' ' << edges[{v, col[v]}] << '\n';
        mp[ {par[v], col[v]}] -= edges[ {v, par[v]}];
        if (col[v] != col[par[v]]) {
          ans -= edges[ {v, par[v]}];
        }
        mp[ {par[v], x}] += edges[ {v, par[v]}];
        if (x != col[par[v]]) {
          ans += edges[ {v, par[v]}];
        }
      }

      // child
      ans += mp[ {v, col[v]}];
      ans -= mp[ {v, x}];

      col[v] = x;
    }

    cout << ans << '\n';
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