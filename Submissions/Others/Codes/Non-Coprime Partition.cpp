#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll sum = (1ll * n * (n + 1)) / 2;
  for (int i = 1; i <= n; i++) {
    ll rem = sum - i;
    if (__gcd(rem, 1ll * i) > 1) {
      cout << "Yes\n";
      cout << 1 << ' ' << i << '\n';
      cout << n - 1 << ' ';
      for (int j = 1; j <= n; j++) {
        if (j == i) continue;
        cout << j << ' ';
      }
      cout << '\n';
      return 0;
    }
  }

  cout << "No\n";

  return 0;
}