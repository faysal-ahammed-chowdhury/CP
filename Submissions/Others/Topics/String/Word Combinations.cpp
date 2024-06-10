#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int N = 5005, K = 1e6 + 9, mod = 1e9 + 7;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(pair<int, int> x) const { return x.first ^ x.second ^ RANDOM; }
};

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
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[K], ipw[K];
void prec() {
  pw[0] = {1, 1};
  for (int i = 1; i < K; i++) {
    pw[i].first = 1ll * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1ll * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] = {1, 1};
  for (int i = 1; i < K; i++) {
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

int dp[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  string s; cin >> s;
  int n = s.size();
  Hashing hash(s);
  int k; cin >> k;
  gp_hash_table<pair<int, int>, int, chash> mp;
  for (int i = 1; i <= k; i++) {
    string x; cin >> x;
    mp[Hashing(x).get_hash()]++;
  }

  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = 0;
    for (int j = 1; j <= i; j++) {
      if (mp.find(hash.get_hash(j, i)) != mp.end()) {
        dp[i] += dp[j - 1];
        dp[i] %= mod;
      }
    }
  }

  cout << dp[n] << '\n';

  return 0;
}