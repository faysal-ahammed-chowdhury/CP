#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  ll a, b, c; cin >> a >> b >> c;
  ll x =  ((a + c) + 1) / 2;
  ll ans = 0;
  if (b <= x) {
    ans += x - b;
  }
  else {
    ans += (b - x) * 2;
  }
  if ((a + c) & 1) ans++;
  cout << ans << '\n';

  return 0;
}