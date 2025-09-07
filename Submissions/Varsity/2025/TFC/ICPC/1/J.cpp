#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1000000007;

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

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
  }

  int ans = 1;
  for (auto [c, cnt] : mp) {
    int x = power(2, cnt - 1, mod);
    ans = 1ll * ans * x % mod;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}