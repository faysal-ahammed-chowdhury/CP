#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 9; // change here

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

const int MOD1 = 127657753, MOD2 = 987654319, MOD3 = 887895641;
const int p1 = 137, p2 = 277, p3 = 389;
int ip1, ip2, ip3;
array<int, 3> pw[N], ipw[N];
void prec() {
  pw[0] = {1, 1, 1};
  for (int i = 1; i < N; i++) {
    pw[i][0] = 1ll * pw[i - 1][0] * p1 % MOD1;
    pw[i][1] = 1ll * pw[i - 1][1] * p2 % MOD2;
    pw[i][2] = 1ll * pw[i - 1][2] * p3 % MOD3;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ip3 = power(p3, MOD3 - 2, MOD3);
  ipw[0] = {1, 1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i][0] = 1ll * ipw[i - 1][0] * ip1 % MOD1;
    ipw[i][1] = 1ll * ipw[i - 1][1] * ip2 % MOD2;
    ipw[i][2] = 1ll * ipw[i - 1][2] * ip3 % MOD3;
  }
}

struct Hashing {
  int n;
  string s;
  vector<array<int, 3>> hash_val;
  Hashing() {}
  Hashing(string _s) {
    s = _s;
    n = s.size();
    hash_val.push_back({0, 0, 0});
    for (int i = 0; i < n; i++) {
      array<int, 3> p;
      p[0] = (hash_val[i][0] + 1ll * s[i] * pw[i][0] % MOD1) % MOD1;
      p[1] = (hash_val[i][1] + 1ll * s[i] * pw[i][1] % MOD2) % MOD2;
      p[2] = (hash_val[i][2] + 1ll * s[i] * pw[i][2] % MOD3) % MOD3;
      hash_val.push_back(p);
    }
  }

  array<int, 3> get_hash(int l, int r) { // 1 indexed
    array<int, 3> ans;
    ans[0] = (hash_val[r][0] - hash_val[l - 1][0] + MOD1) * 1ll * ipw[l - 1][0] % MOD1;
    ans[1] = (hash_val[r][1] - hash_val[l - 1][1] + MOD2) * 1ll * ipw[l - 1][1] % MOD2;
    ans[2] = (hash_val[r][2] - hash_val[l - 1][2] + MOD3) * 1ll * ipw[l - 1][2] % MOD3;
    return ans;
  }
  array<int, 3> get_hash() { // 1 indexed
    return get_hash(1, n);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  return 0;
}