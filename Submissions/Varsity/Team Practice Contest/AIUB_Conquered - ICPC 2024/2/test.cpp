#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 9, M = 15; 

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

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277; // change here
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

struct Hashing {
  int n;
  string s;
  vector<pair<int, int>> hash_val;
  Hashing() {}
  Hashing(string _s) {
    s = _s;
    n = s.size();
    hash_val.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
      pair<int, int> p;
      p.first = (hash_val[i].first + 1ll * s[i] * pw[i].first % MOD1) % MOD1;
      p.second = (hash_val[i].second + 1ll * s[i] * pw[i].second % MOD2) % MOD2;
      hash_val.push_back(p);
    }
  }

  pair<int, int> get_hash(int l, int r) { // 1 indexed
    pair<int, int> ans;
    ans.first = (hash_val[r].first - hash_val[l - 1].first + MOD1) * 1ll * ipw[l - 1].first % MOD1;
    ans.second = (hash_val[r].second - hash_val[l - 1].second + MOD2) * 1ll * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<int, int> get_hash() { // 1 indexed
    return get_hash(1, n);
  }
};

int n, m;
string s;
string pattern[M];
vector<pair<int, int>> range[M];
map<pair<int, int>, int> dp;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

int f(int mask, int last) {
  if (__builtin_popcount(mask) == m) return 1;
  if (dp.count({mask, last})) return dp[{mask, last}];
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (CHECK(mask, i)) continue;
    auto it = lower_bound(range[i].begin(), range[i].end(), make_pair(last + 1, 0ll));
    if (it == range[i].end()) return dp[{mask, last}] = 0;
    int new_last = (*it).second;
    ans += f(mask | (1 << i), new_last);
  }
  return dp[{mask, last}] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  cin >> n >> m;
  cin >> s;
  for (int i = 1; i <= m; i++) {
    string t; cin >> t;
    pattern[i] = t;
  }

  Hashing hash(s);

  for (int j = 1; j <= m; j++) {
    Hashing hashp(pattern[j]);
    int x = pattern[j].size();
    for (int i = 1; i + x - 1 <= n; i++) {
      if (hash.get_hash(i, i + x - 1) == hashp.get_hash()) {
        range[j].push_back({i, i + x - 1});
      }
    }
  }

  // for (int i = 1; i <= m; i++) {
  //   cout << i << ": \n";
  //   for (auto [l, r] : range[i]) {
  //     cout << l << ' ' << r << '\n';
  //   }
  // }

  cout << f(0, 0) << '\n';

  return 0;
}