#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  ll prefix[n + 1];
  prefix[0] = 0;
  for (int i = 1; i <= n; i++) {
    prefix[i] = prefix[i - 1] + a[i];
  }

  int two_into_a_into_b_for_all_pairs = 0;
  for (int i = 1; i <= n; i++) {
    ll sum = (prefix[n] - prefix[i]) % mod;
    two_into_a_into_b_for_all_pairs += (1ll * a[i] * sum) * 2 % mod;
    two_into_a_into_b_for_all_pairs %= mod;
  }

  int a_square_plus_b_square_for_all_pairs = 0;
  for (int i = 1; i <= n; i++) {
    a_square_plus_b_square_for_all_pairs += (1ll * a[i] * a[i] % mod * (n - 1) % mod);
    a_square_plus_b_square_for_all_pairs %= mod;
  }

  int ans = (two_into_a_into_b_for_all_pairs + a_square_plus_b_square_for_all_pairs) % mod;
  cout << ans << '\n';

  return 0;
}