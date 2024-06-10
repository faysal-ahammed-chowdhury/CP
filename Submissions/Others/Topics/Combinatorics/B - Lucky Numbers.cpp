#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  long long ans = 0;
  // for (int i = 1; i <= n; i++) {
  //   ans += (1ll << i);
  // }
  ans += (1ll << (n + 1)) - 2;
  cout << ans << '\n';

  return 0;
}