#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, q; cin >> n >> k >> q;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] = a[i] - i;
  }
  map<int, int> mp;
  multiset<int> ms;
  int ans[n + 1];
  for (int i = 1; i <= n; i++)  {
    auto it = ms.find(mp[a[i]]);
    if (it != ms.end()) ms.erase(it);
    mp[a[i]]++;
    ms.insert(mp[a[i]]);
    if (i >= k) {
      ans[i] = k;
      if (!ms.empty()) ans[i] = k - (*ms.rbegin());
      auto it = ms.find(mp[a[i - k + 1]]);
      if (it != ms.end()) ms.erase(it);
      mp[a[i - k + 1]]--;
      ms.insert(mp[a[i - k + 1]]);
    }
  }
  while (q--) {
    int l, r; cin >> l >> r;
    cout << ans[r] << '\n';
  }
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