#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
using ll = long long;

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
  int n, k; cin >> n >> k;
  ll a[n + 1];
  a[0] = 0;
  ll sum = 0;
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for(int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  ll low = 0;
  ll max_subarray_sum = INT64_MIN;
  for(int i = 1; i <= n; i++) {
    max_subarray_sum = max(max_subarray_sum, a[i] - low);
    low = min(low, a[i]);
  }
  max_subarray_sum = max(0ll, max_subarray_sum);
  max_subarray_sum %= mod;

  sum = ((sum % mod) + mod) % mod;

  int pw = (power(2, k, mod) - 1);
  if (pw < 0) pw += mod;
  int series = 1ll * max_subarray_sum * pw % mod;
  int ans = (sum + series) % mod;
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