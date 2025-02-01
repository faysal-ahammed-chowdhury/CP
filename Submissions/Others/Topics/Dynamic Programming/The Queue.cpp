#include <bits/stdc++.h>
using namespace std;

const int N = 1005, mod = 1e9 + 7;
int fact[N], ifact[N];
int n, par[N], dp[N], sz[N];
vector<int> g[N];

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int inverse(int x) {
  return power(x, mod - 2, mod);
}

void prec() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = 1ll * fact[i - 1] * i % mod;
  }
  ifact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) {
    ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
  }
}

int nCr(int n, int r) {
  if (r > n) return 0;
  return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int nPr(int n, int r) {
  if (r > n) return 0;
  return 1ll * fact[n] * ifact[n - r] % mod;
}

void dfs(int u) {
  // cout << u << '\n';
  dp[u] = 1;
  sz[u] = 1;
  int tot_sz = 0;
  for (auto v : g[u]) {
    dfs(v);
    tot_sz += sz[v];
    sz[u] += sz[v];
    dp[u] = 1ll * (1ll * dp[u] * dp[v] % mod) * (1ll * nCr(tot_sz, sz[v]) % mod) % mod;
  }
}

int cs = 0;
void solve() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    g[i].clear();
    par[i] = -1;
    sz[i] = 0;
    dp[i] = 0;
  }

  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    par[v] = u;
  }

  int p = -1;
  for (int i = 1; i <= n; i++) {
    if (par[i] == -1) {
      p = i;
      break;
    }
  }

  assert(p != -1);
  dfs(p);
  cout << "Case " << ++cs << ": " << dp[p] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}