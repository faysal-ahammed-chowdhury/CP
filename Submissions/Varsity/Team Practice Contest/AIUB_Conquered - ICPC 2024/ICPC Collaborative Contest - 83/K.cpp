#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9; // change here

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  int n; cin >> n;
  Hashing hs[n + 1];
  string s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    hs[i] = Hashing(s[i]);
  }

  int q; cin >> q;
  string l[q + 1], r[q + 1];
  set<int> se1, se2;
  set<pair<int, int>> se3;
  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];
    se1.insert(l[i].size());
    se2.insert(r[i].size());
    se3.insert({l[i].size(), r[i].size()});
  }

  map<pair<int, int>, int> mp1, mp2;
  map<pair<pair<int, int>, pair<int, int>>, int> mp3;

  for (auto len : se1) {
    for (int i = 1; i <= n; i++) {
      if (s[i].size() >= len) mp1[hs[i].get_hash(1, len)]++;
    }
  }

  for (auto len : se2) {
    for (int i = 1; i <= n; i++) {
      int sz = s[i].size();
      if (s[i].size() >= len) mp2[hs[i].get_hash(sz - len + 1, sz)]++;
    }
  }

  for (auto [len1, len2] : se3) {
    for (int i = 1; i <= n; i++) {
      if (s[i].size() >= len1 and s[i].size() >= len2) {
        int sz = s[i].size();
        mp3[ {hs[i].get_hash(1, len1), hs[i].get_hash(sz - len2 + 1, sz)}]++;
      }
    }
  }

  for (int i = 1; i <= q; i++) {
    Hashing h1(l[i]);
    Hashing h2(r[i]);
    int ans = mp1[h1.get_hash()];
    ans += mp2[h2.get_hash()];
    ans -= mp3[ {h1.get_hash(), h2.get_hash()}];
    cout << ans << '\n';
  }

  return 0;
}