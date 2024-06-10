#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1], mx_val = 0;
  set<int> se;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    se.insert(a[i]);
    mx_val = max(mx_val, a[i]);
  }
  sort(a + 1, a + n + 1);
  map<int, int> mp, freq;
  for (int i = 1; i <= n; i++) {
    mp[a[i]] = i;
    freq[a[i]]++;
  }
  bool not_ok[n + 1];
  memset(not_ok, 0, sizeof(not_ok));
  for (auto x : se) {
    for (int j = x + x; j <= mx_val; j += x) {
      if (mp.find(j) != mp.end()) {
        not_ok[mp[j]] = true;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (not_ok[i] or freq[a[i]] > 1) continue;
    ans++;
  }
  cout << ans << '\n';

  return 0;
}