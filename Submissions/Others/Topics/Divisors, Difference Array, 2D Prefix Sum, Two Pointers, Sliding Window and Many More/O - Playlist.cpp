#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<int, int> mp;
  int r = 1, ans = 0;
  for (int l = 1; l <= n; l++) {
    while (r <= n) {
      mp[a[r]]++;
      r++;
      if (mp.size() != (r - l)) {
        r--;
        mp[a[r]]--;
        if (mp[a[r]] == 0) {
          mp.erase(a[r]);
        }
        break;
      }
    }
    ans = max(ans, r - l);
    mp[a[l]]--;
    if (mp[a[l]] == 0) {
      mp.erase(a[l]);
    }
  }
  cout << ans << '\n';

  return 0;
}