#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  int m; cin >> m;
  int d[m + 1];
  for (int i = 1; i <= m; i++) {
    cin >> d[i];
  }
  map<int, int> mp;
  set<int> need, no_need;
  int need_cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == b[i]) {
      no_need.insert(a[i]);
    }
    else {
      need.insert(b[i]);
      need_cnt++;
      mp[b[i]]++;
    }
  }
  bool flag = false;
  for (int i = 1; i <= m; i++) {
    if (mp[d[i]] > 0) {
      need_cnt--;
      mp[d[i]]--;
      continue;
    }
    if (flag) {
      if (need.find(d[i]) != need.end() or no_need.find(d[i]) != no_need.end()) {
        flag = false;
        continue;
      }
    }
    if (no_need.find(d[i]) != no_need.end()) continue;
    if (need.find(d[i]) != need.end()) continue;
    if (need_cnt > 0) continue;
    flag = true;
  }
  if (!flag and need_cnt == 0) cout << "YES\n";
  else cout << "NO\n";
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