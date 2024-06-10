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

  vector<pair<int, int>> ans;
  set<int> se;
  for (int i = 1, j = 1; i <= n;) {
    while (j <= n and se.find(a[j]) == se.end()) {
      se.insert(a[j++]);
    }
    if (i <= n and j <= n) {
      ans.push_back(make_pair(i, j));
    }
    se.clear();
    j++, i = j;
  }

  if (ans.size() == 0) {
    cout << -1 << '\n';
  }
  else {
    cout << ans.size() << '\n';
    ans[ans.size() - 1].second = n;
    for (auto [x, y] : ans) {
      cout << x << ' ' << y << '\n';
    }
  }

  return 0;
}