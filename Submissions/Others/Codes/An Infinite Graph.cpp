#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

const int N = 1e6 + 9, LOG = 20;
vector<bool> is_prime(N, true);
vector<int> primes;
vector<int> g[N];

int par[N][LOG], depth[N];

void dfs(int u, int p) {
  par[u][0] = p;
  depth[u] = depth[p] + 1;
  for (int i = 1; i < LOG; i++) {
    par[u][i] = par[par[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
    }
  }
}

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }
  int k = depth[u] - depth[v];
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  if (u == v) return u;
  for (int i = LOG - 1; i >= 0; i--) {
    if (par[u][i] != par[v][i]) {
      u = par[u][i];
      v = par[v][i];
    }
  }
  return par[u][0];
}

int kth(int u, int k) {
  assert(k >= 0);
  for (int i = 0; i < LOG; i++) {
    if (CHECK(k, i)) u = par[u][i];
  }
  return u;
}

int dist(int u, int v) {
  int l = lca(u, v);
  return (depth[u] - depth[l]) + (depth[v] - depth[l]);
}

void sieve() {
  is_prime[1] = false;
  int lim = sqrt(N + 1);
  for (int i = 2; i <= lim; i++) {
    if (is_prime[i]) {
      for (int j = i + i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int cs = 0;
void solve() {
  int n; cin >> n;

  if (n == 2) {
    cout << 1 << '\n';
    cout << 2 << '\n';
    cout << 0 << '\n';
    return;
  }

  for (auto i : primes) {
    int need = n - i;
    if (i <= need and is_prime[need]) {
      cout << 2 << '\n';
      cout << i << ' ' << need << '\n';
      auto it1 = lower_bound(primes.begin(), primes.end(), i) - primes.begin() + 1;
      auto it2 = lower_bound(primes.begin(), primes.end(), need) - primes.begin() + 1;
      cout << dist(it1, it2) << '\n';
      return;
    }
  }
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  sieve();
  for (int i = 2; i < N; i++) {
    if (is_prime[i]) primes.push_back(i);
  }

  for (int i = 1; i < N; i++) {
    int l = i * 2;
    int r = l + 1;
    if (l < N) g[i].push_back(l);
    if (r < N) g[i].push_back(r);
  }
  dfs(1, 0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}