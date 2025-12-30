#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll, ll> f(ll n) {
  if (n == 1) {
    return {0, 1};
  }
  if (n == 3) {
    return {1, 1};
  }

  ll m = n;
  int cnt = 0;
  while (n % 2 == 0) {
    cnt++;
    n /= 2;
  }

  if (n == 1 or n == 3) {
    int ans = cnt;
    if (n == 3) ans++;
    return {ans, 1};
  }

  cnt -= 2;
  n <<= 2;

  n += 4;
  cnt++;
  return {cnt, n};
}

void solve() {
  ll n; cin >> n;
  if (n == 1) {
    cout << "0\n";
    return;
  }
  if (n <= 3) {
    cout << "1\n";
    return;
  }
  ll m = n;
  int cnt = 0;
  while (n % 2 == 0) {
    cnt++;
    n /= 2;
  }

  if (n == 1 or n == 3) {
    int ans = cnt;
    if (n == 3) ans++;
    cout << ans << "\n";
  }
  else {
    if (cnt >= 2) {
      int ans = 0;
      while (true) {
        auto [add, val] = f(m);
        // cout << add << ' ' << val << '\n';
        // break;
        ans += add;
        if (val == 1) break;
        m = val;
      }

      cout << ans << '\n';
      return;
    }
    cout << "-1\n";
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