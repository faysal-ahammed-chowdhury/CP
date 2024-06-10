#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  int a[n + 1]; long long pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  map<int, int> mp;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (pref[i] % m == 0) ans++;
    ans += mp[pref[i] % m];
    mp[pref[i] % m]++;
  }
  cout << ans << '\n';

  return 0;
}