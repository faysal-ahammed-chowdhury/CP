#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  ll pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }
  ll ans = 0;
  map<ll, int> mp;
  for (int i = 1; i <= n; i++) {
    if (pref[i] == 0) ans++;
    ans += mp[pref[i]];
    mp[pref[i]]++;
  }
  cout << ans << '\n';

  return 0;
}