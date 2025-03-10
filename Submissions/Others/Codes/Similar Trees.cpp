#include <bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> g1[N], g2[N];
vector<pair<int, int>> hash1[N], hash2[N];
int n, m, par1[N], par2[N], sz1[N], sz2[N];

void f(string &s) {
  int node = 1, cur = 1;
  for (auto c : s) {
    if (c == '1') {
      node++;
      g1[cur].push_back(node);
      g1[node].push_back(cur);
      par1[node] = cur;
      cur = node;
    }
    else {
      cur = par1[cur];
    }
  }
  n = node;
}

void f2(string &s) {
  int node = 1, cur = 1;
  for (auto c : s) {
    if (c == '1') {
      node++;
      g2[cur].push_back(node);
      g2[node].push_back(cur);
      par2[node] = cur;
      cur = node;
    }
    else {
      cur = par2[cur];
    }
  }

  m = node;
}

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
    g1[i].clear();
    g2[i].clear();
    hash1[i].clear();
    hash2[i].clear();
    sz1[i] = sz2[i] = 0;
    par1[i] = par2[i] = -1;
  }
}

void dfs(int u, int p, int lvl) {
  sz1[u] = 1;
  bool leaf = true;
  for (auto v : g1[u]) {
    if (v != p) {
      dfs(v, u, lvl + 1);
      sz1[u] += sz1[v];
      leaf = false;
    }
  }
  pair<int, int> my_hash;
  my_hash.first = 1ll * sz1[u] * pw[lvl].first % MOD1;
  my_hash.second = 1ll * sz1[u] * pw[lvl].second % MOD2;
  if (!leaf) {
    int sum1 = 0, sum2 = 0;
    for (auto here : hash1[u]) {
      auto [x, y] = here;
      sum1 = (sum1 + x) % MOD1;
      sum2 = (sum2 + y) % MOD2;
    }
    my_hash.first = power(my_hash.first, sum1, MOD1);
    my_hash.second = power(my_hash.second, sum2, MOD2);
  }
  hash1[p].push_back(my_hash);
}

void dfs2(int u, int p, int lvl) {
  sz2[u] = 1;
  bool leaf = true;
  for (auto v : g2[u]) {
    if (v != p) {
      dfs2(v, u, lvl + 1);
      sz2[u] += sz2[v];
      leaf = false;
    }
  }
  pair<int, int> my_hash;
  my_hash.first = 1ll * sz2[u] * pw[lvl].first % MOD1;
  my_hash.second = 1ll * sz2[u] * pw[lvl].second % MOD2;
  if (!leaf) {
    int sum1 = 0, sum2 = 0;
    for (auto here : hash2[u]) {
      auto [x, y] = here;
      sum1 = (sum1 + x) % MOD1;
      sum2 = (sum2 + y) % MOD2;
    }
    my_hash.first = power(my_hash.first, sum1, MOD1);
    my_hash.second = power(my_hash.second, sum2, MOD2);
  }
  hash2[p].push_back(my_hash);
}

int cs;
void solve() {
  cout << "Case " << ++cs << ": ";
  string s, t;
  getline(cin, s);
  getline(cin, t);

  f(s);
  f2(t);

  dfs(1, 0, 1);
  dfs2(1, 0, 1);

  if (hash1[0][0] == hash2[0][0]) {
    cout << "Same\n";
  }
  else {
    cout << "Different\n";
  }

  clr(n);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  int t = 1; cin >> t;
  cin.ignore();
  cin.ignore();
  while (t--) {
    solve();
  }

  return 0;
}