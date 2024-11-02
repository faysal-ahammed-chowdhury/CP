#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

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


const int N = 1005;

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


Hashing hs[105];
int n, mx;
string s[105];
gp_hash_table<pair<int, int>, pair<int, int>, custom_hash> idx;

bool ok(int len) {
  gp_hash_table<pair<int, int>, int, custom_hash> mp;
  for (int i = 1; i <= n; i++) {
    gp_hash_table<pair<int, int>, int, custom_hash> tmp;
    for (int j = 1; j + len - 1 <= s[i].size(); j++) {
      if (tmp.find(hs[i].get_hash(j, j + len - 1)) != tmp.end()) continue;
      mp[hs[i].get_hash(j, j + len - 1)]++;
      if (mp[hs[i].get_hash(j, j + len - 1)] > (n / 2)) return true;
      tmp[(hs[i].get_hash(j, j + len - 1))] = 1;
    }
  }
  return false;
}

int lcp(int first, int second, int i, int j, int x, int y) {
  int len1 = j - i + 1, len2 = y - x + 1;
  int l = 1, r = min(len1, len2), ans = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (hs[first].get_hash(i, i + mid - 1) == hs[second].get_hash(x, x + mid - 1)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  return ans;
}

struct cmp {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    int first = idx[a].first;
    int i = idx[a].second;
    int j = i + mx - 1;
    int second = idx[b].first;
    int x = idx[b].second;
    int y = x + mx - 1;
    int common_prefix = lcp(first, second, i, j, x, y);
    int len1 = j - i + 1, len2 = y - x + 1;
    if (common_prefix == len1 and len1 == len2) return false;
    else if (common_prefix == len1) return true;
    else if (common_prefix == len2) return false;
    else return (s[first][i + common_prefix - 1] < s[second][x + common_prefix - 1] ? true : false);
  }
};


int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec();

  while (cin >> n and n) {
    for (int i = 1; i <= n; i++) {
      cin >> s[i];
      hs[i] = Hashing(s[i]);
    }

    int l = 1, r = 1000, len = 0;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid)) {
        len = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    // cout << len << '\n';

    if (len == 0) {
      cout << "?\n\n";
      continue;
    }

    mx = len;

    set<pair<int, int>, cmp> se;
    gp_hash_table<pair<int, int>, int, custom_hash> mp;
    for (int i = 1; i <= n; i++) {
      gp_hash_table<pair<int, int>, int, custom_hash> tmp;
      for (int j = 1; j + len - 1 <= s[i].size(); j++) {
        if (tmp.find(hs[i].get_hash(j, j + len - 1)) != tmp.end()) continue;
        mp[hs[i].get_hash(j, j + len - 1)]++;
        if (mp[hs[i].get_hash(j, j + len - 1)] > (n / 2)) {
          idx[hs[i].get_hash(j, j + len - 1)] = {i, j};
          se.insert(hs[i].get_hash(j, j + len - 1));
        }
        tmp[(hs[i].get_hash(j, j + len - 1))] = 1;
      }
    }

    for (auto hash : se) {
      auto [i, l] = idx[hash];
      int r = l + len - 1;
      for (int j = l; j <= r; j++) {
        cout << s[i][j - 1];
      }
      cout << '\n';
    }

    cout << '\n';
  }

  return 0;
}