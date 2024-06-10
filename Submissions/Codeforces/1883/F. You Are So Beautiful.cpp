#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1];
  map<int, pair<int, int>> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (mp.find(a[i]) == mp.end()) {
      mp[a[i]].first = i;
      mp[a[i]].second = i;
    } 
    else {
      mp[a[i]].second = i;
    }
  }

  int starts[n + 1], ends[n + 1];
  memset(starts, 0, sizeof starts);
  memset(ends, 0, sizeof ends);

  for (auto i : mp) {
    starts[i.second.first] = 1;
    ends[i.second.second] = 1;
  }

  for (int i = 1; i <= n; i++) {
    ends[i] += ends[i - 1];
  }

  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (starts[i]) {
      ans += ends[n] - ends[i - 1];
    }
  }
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}