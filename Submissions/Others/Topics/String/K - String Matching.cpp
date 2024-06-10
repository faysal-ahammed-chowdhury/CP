#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9;

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

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
pair<int, int> pw[N], ipw[N];

void prec() {
  pw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1ll * p1 * pw[i - 1].first % MOD1;
    pw[i].second = 1ll * p2 * pw[i - 1].second % MOD2;
  }
  int ip1 = power(p1, MOD1 - 2, MOD1);
  int ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1ll * ip1 * ipw[i - 1].first % MOD1;
    ipw[i].second = 1ll * ip2 * ipw[i - 1].second % MOD2;
  }
}

pair<int, int> get_hash(string &s) {
  int n = s.size();
  pair<int, int> hash_val = {0, 0};
  for (int i = 0; i < n; i++) {
    hash_val.first += 1ll * s[i] * pw[i].first % MOD1;
    hash_val.first %= MOD1;
    hash_val.second += 1ll * s[i] * pw[i].second % MOD2;
    hash_val.second %= MOD2;
  }
  return hash_val;
}

pair<int, int> pref[N];
void build(string &s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    pref[i].first = 1ll * s[i] * pw[i].first % MOD1;
    pref[i].first %= MOD1;
    if (i) pref[i].first = (pref[i - 1].first + pref[i].first) % MOD1;
    pref[i].second = 1ll * s[i] * pw[i].second % MOD2;
    pref[i].second %= MOD2;
    if (i) pref[i].second = (pref[i - 1].second + pref[i].second) % MOD2;
  }
}

pair<int, int> get_hash(int i, int j) {
  pair<int, int> hash_val;
  hash_val.first = 1ll * (pref[j].first - (i ? pref[i - 1].first : 0) + MOD1) * ipw[i].first % MOD1;
  hash_val.second = 1ll * (pref[j].second - (i ? pref[i - 1].second : 0) + MOD2) * ipw[i].second % MOD2;
  return hash_val;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  prec();
  string s1, s2; cin >> s1 >> s2;
  build(s1);
  pair<int, int> hash_s2 = get_hash(s2);
  int x = s2.length(), n = s1.length();
  int ans = 0;
  for (int i = 0; i + x - 1 < n; i++) {
    if (get_hash(i, i + x - 1) == hash_s2) ans++;
  }
  cout << ans << '\n';

  return 0;
}