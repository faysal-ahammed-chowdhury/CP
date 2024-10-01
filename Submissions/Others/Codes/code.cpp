#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  vector<array<int, 2>> v;
  while (m--) {
    int a, c; cin >> a >> c;
    v.push_back({c, a});
  }
  sort(v.begin(), v.end());

  int gc = n, tmp = n;
  int ans = 0;
  for (auto [c, a] : v) {
    gc = __gcd(gc, a);
    if (n % gc != 0 or gc == 1) {
      ans += c * (tmp - 1);
      cout << ans << '\n';
      return 0;
    }
    int cnt = (tmp - gc);
    ans += cnt  * c;
    tmp = gc;
  }
  cout << -1 << '\n';

  return 0;
}