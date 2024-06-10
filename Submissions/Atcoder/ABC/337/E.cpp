#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  int n; cin >> n;
  int x = n - 1;
  int m = __lg(x);

  map<int, vector<int>> mp;
  for (int i = 0; i <= x; i++) {
    for (int k = 0; k <= m; k++) {
      if ((i & (1 << k))) {
        mp[k].push_back(i + 1);
      }
    }
  }

  cout << m + 1 << '\n';
  for (auto [x, v] : mp) {
    cout << mp[x].size() << ' ';
    for (auto x : v) {
      cout << x << ' ';
    }
    cout << '\n';
  }

  string s; cin >> s;
  int ans = 1;
  for (int i = 0; i <= m; i++) {
    if (s[i] == '1') {
      ans += (1 << i);
    }
  }

  cout << ans << '\n';

  return 0;
}