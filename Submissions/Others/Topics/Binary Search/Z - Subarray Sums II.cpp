#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, x; cin >> n >> x;
  ll a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    a[i] += a[i - 1];
  }
  map<ll, int> mp;
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == x) ans++;
    ll need = a[i] - x;
    ans += mp[need];
    mp[a[i]]++;
  }
  cout << ans << '\n';

  return 0;
}