#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  long long n; cin >> n;
  long long ans = 1e18;
  for (int i = 1; 1ll * i * i <= n; i++) {
    if (n % i == 0) {
      long long x = i, y = n / i;
      ans = min(ans, x + y - 2);
    }
  }
  cout << ans << '\n';

  return 0;
}