#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int d; cin >> d;
  int ans = 1e18;
  for (int i = 0; i <= 1e6 + 9; i++) {
    int sqr = i * i;
    int need = d - sqr;
    int x = sqrtl(need);
    int y = x + 1;
    y *= y;
    x *= x;
    ans = min(ans, abs(sqr + x - d));
    ans = min(ans, abs(sqr + y - d));
  }
  cout << ans << '\n';

  return 0;
}