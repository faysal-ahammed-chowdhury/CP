#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  int pref[n + 1];
  memset(pref, 0, sizeof pref);

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + (s[i] == 'a' ? +1 : -1);
  }

  int extra = pref[n];
  if (extra == 0) {
    cout << 0 << '\n';
    return;
  }

  map<int, int> mp;
  mp[0] = 0;
  int ans = n;
  for (int i = 1; i <= n; i++) {
    int need = pref[i] - extra;
    if (mp.find(need) != mp.end()) {
      ans = min(ans, i - mp[need]);
    }
    mp[pref[i]] = i;
  }

  if (ans == n) ans = -1;
  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}