#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, s, k; cin >> n >> s >> k;

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x, y; cin >> x >> y;
    ans += x * y;
  }

  if (ans < s) {
    ans += k;
  }
  cout << ans << '\n';

  return 0;
}