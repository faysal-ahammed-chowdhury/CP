#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  ll a[n + 1];
  ll sum = 0;
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }

  if (sum % 3 != 0) {
    cout << 0 << '\n';
    return 0;
  }

  ll per = sum / 3;

  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }

  map<ll, ll> mp;
  ll ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == 2 * per) {
      ans += mp[per];
    }
    mp[a[i]]++;
  }
  cout << ans << '\n';

  return 0;
}