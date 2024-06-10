#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
struct chash {
  int operator()(int x) const { return x ^ RANDOM; }
};

const int N = 12, K = 21;
int base, k, n;
long long pw[13], dp[N][(1 << N) + 2][K];
string s;
gp_hash_table<char, int, chash> mp;

long long fun(int i, int mask, int rem) {
  if (__builtin_popcount(mask) >= n) {
    return rem == 0;
  }
  long long &ans = dp[i][mask][rem];
  if (ans != -1) return ans;

  ans = 0;
  for (int j = 0; j < n; j++) {
    if (!(mask & (1 << j))) {
      int x = (rem + (1ll * mp[s[j]] * pw[i] % k)) % k;
      ans += fun(i + 1, mask | (1 << j), x);
    }
  }
  return ans;
}

int cs = 0;
void solve() {
  cin >> base >> k >> s;
  n = s.size();
  for (int i = 0; i <= n; i++) {
    pw[i] = round(pow(base, i));
  }
  memset(dp, -1, sizeof(dp));
  cout << "Case " << ++cs << ": ";
  cout << fun(0, 0, 0) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (char c = '1'; c <= '9'; c++) {
    mp[c] = c - '0';
  }
  int id = 9;
  for (char c = 'A'; c <= 'F'; c++) {
    mp[c] = ++id;
  }

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}