#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    mp[x]++;
  }

  int ans = 0;
  for (auto [x, y] : mp) {
    if (y >= x) {
      ans += abs(y - x);
    }
    else {
      ans += y;
    }
  }

  cout << ans << '\n';

  return 0;
}