#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int pref1[n + 1], pref2[n + 1];
  memset(pref1, 0, sizeof(pref1));
  memset(pref2, 0, sizeof(pref2));
  s = '.' + s;
  for (int i = 1; i <= n; i++) {
    pref1[i] += pref1[i - 1] + (s[i] == '1');
    pref2[i] += pref2[i - 1] + (s[i] == '0');
  }

  long long ans = 0;
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    if (pref1[i] == pref2[i]) ans++;
    ans += mp[pref1[i] - pref2[i]];
    mp[pref1[i] - pref2[i]]++;
  }
  ans = (1ll * n * (n + 1) / 2) + ans;
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