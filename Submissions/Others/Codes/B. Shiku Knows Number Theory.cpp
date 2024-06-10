#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  int ans = 0;
  for (int i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      if (i <= n and (x / i) <= n) {
        ans++;
        if (i != (x / i)) ans++;
      }
    }
  }
  cout << ans << '\n';

  return 0;
}