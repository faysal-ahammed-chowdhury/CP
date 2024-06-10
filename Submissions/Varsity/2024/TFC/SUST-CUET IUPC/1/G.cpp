#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

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
  vector<int> a(n);
  map<int, int> cnt;
  for (auto &x : a) {
    cin >> x;
    cnt[x]++;
  }
  sort(a.begin(), a.end());
  int max_mex = 0;
  for (auto x : a) {
    if (max_mex == x) max_mex++;
  }
  int ways[max_mex];
  for (int i = 0; i < max_mex; i++) {
    ways[i] = power(2, cnt[i], mod) - 1;
    ways[i] += mod;
    ways[i] %= mod;
  }
  for (int i = 1; i < max_mex; i++) {
    ways[i] = (1ll * ways[i] * ways[i - 1] % mod);
  }

  int ans = 0;
  for (int cur = 1; cur <= max_mex; cur++) {
    int right = n - (upper_bound(a.begin(), a.end(), cur) - a.begin());
    int possible = power(2, right, mod);
    possible = (1ll * ways[cur - 1] * possible % mod);
    ans += 1ll * cur * possible % mod;
    ans %= mod;
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}