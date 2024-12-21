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

  int ans = 0;
  for (int d = 1; d <= n; d++) {
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
      mp[i % d].push_back(a[i]);
    }
    int cur = 0;
    for (auto [x, v] : mp) {
      if (v.empty()) continue;
      int last = v[0], cnt = 1;
      for (int j = 1; j < v.size(); j++) {
        if (v[j] == last) {
          cnt++;
        }
        else {
          cur = max(cnt, cur);
          last = v[j];
          cnt = 1;
        }
      }
      cur = max(cnt, cur);
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';

  return 0;
}