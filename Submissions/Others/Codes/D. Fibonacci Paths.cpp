#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 9, mod = 998244353;
vector<int> g[N], gT[N];
int n, m, a[N];
map<pair<int, int>, int> dp, dp2;

void clr(int n) {
  dp.clear();
  dp2.clear();
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    gT[i].clear();
  }
}

int f(int u, int v);
int f2(int u, int need) {
  if (dp2.find({u, need}) != dp2.end()) return dp2[ {u, need}];
  int ans = 0;
  for (auto p : gT[u]) {
    if (a[p] == need) ans = (ans + f(p, u)) % mod;
  }
  return dp2[ {u, need}] = ans;
}

int f(int u, int v) {
  if (a[u] >= a[v]) {
    return 1;
  }

  if (dp.find({u, v}) != dp.end()) return dp[ {u, v}];

  int need = a[v] - a[u];
  int ans = 1 + f2(u, need);
  // for (auto p : gT[u]) {
  //   if (a[p] == need) ans = (ans + f(p, u)) % mod;
  // }
  return dp[ {u, v}] = ans;
}

void solve() {
  cin >> n >> m;
  clr(n);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    gT[v].push_back(u);
  }

  int ans = 0;
  for (int u = 1; u <= n; u++) {
    for (auto v : g[u]) {
      ans = (ans + f(u, v)) % mod;
    }
  }
  cout << ans << '\n';
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