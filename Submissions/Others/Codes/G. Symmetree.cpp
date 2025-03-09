#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int N = 2e5 + 9;
vector<int> g[N];
vector<array<int, 3>> hassh[N];
int n, sz[N];

int power(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

const int MOD1 = 1e9 + 9, MOD2 = 1e9 + 21;
const int p1 = 1e5 + 19, p2 = 1e5 + 43; 
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1ll * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1ll * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1ll * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1ll * ipw[i - 1].second * ip2 % MOD2;
  }
}

void clr(int n) {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
    hassh[i].clear();
    sz[i] = 0;
  }
}

void dfs(int u, int p) {
  sz[u] = 1;
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
}

void dfs2(int u, int p, int lvl) {
  array<int, 3> my_hash;
  my_hash[0] = 1ll * sz[u] * pw[lvl].first % MOD1;
  my_hash[1] = 1ll * sz[u] * pw[lvl].second % MOD2;
  my_hash[2] = u;
  bool leaf = true;
  for (auto v : g[u]) {
    if (v != p) {
      dfs2(v, u, lvl + 1);
      leaf = false;
    }
  }
  if (!leaf) {
    int sum1 = 0, sum2 = 0;
    for (auto here : hassh[u]) {
      auto [x, y, _] = here;
      // my_hash[0] = (my_hash[0] + x) % MOD1;
      // my_hash[1] = (my_hash[1] + y) % MOD2;
      sum1 = (sum1 + x) % MOD1;
      sum2 = (sum2 + y) % MOD2;
    }
    my_hash[0] = power(my_hash[0], sum1, MOD1);
    my_hash[1] = power(my_hash[1], sum2, MOD2);
  }
  hassh[p].push_back(my_hash);
}

bool ok(int u) {
  // cout << u << '\n';
  map<pair<int, int>, int> mp;
  for (auto [x, y, who] : hassh[u]) {
    mp[{x, y}]++;
  }
  int odd = 0;
  pair<int, int> val;
  for (auto [here, cnt] : mp) {
    odd += cnt & 1;
    if (cnt & 1) val = here;
  }

  if (odd == 0) return true;
  if (odd > 1) return false;

  int node;
  for (auto [x, y, who] : hassh[u]) {
    pair<int, int> here = {x, y};
    if (here == val) node = who;
  }

  return ok(node);
}

void solve() {
  cin >> n;
  clr(n);
  for (int i = 2; i <= n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  dfs2(1, 0, 1);

  if (ok(0)) cout << "YES\n";
  else cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}