#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  map<int, vector<int>> mp;
  for (int i = 1; i <= m; i++) {
    int x, y; cin >> x >> y;
    mp[x].push_back(y);
    mp[y].push_back(x);
  }

  int l = 1, r = 1;
  long long ans = 0;
  map<int, int> cnt;
  while (l <= n) {
    while (r <= n) {
      if (cnt.find(r) == cnt.end()) {
        ans += r - l + 1;
        for (auto x : mp[r]) {
          cnt[x]++;
        }
        r++;
      }
      else {
        break;
      }
    }
    for (auto x : mp[l]) {
      cnt[x]--;
      if (cnt[x] == 0) cnt.erase(x);
    }
    l++;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}