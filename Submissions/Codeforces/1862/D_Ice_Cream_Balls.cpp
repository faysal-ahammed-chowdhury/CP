#include <bits/stdc++.h>
using namespace std;

// @author: Faaysal

#define ll unsigned long long
ll n;

bool ok(ll cup) {
  __int128 possible = ((__int128)cup * (cup - 1)) >> 1;
  return possible <= n;
}

void solve() {
  cin >> n;
  ll l = 2, r = 1e18, ans = -1;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (ok(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else {
      r = mid - 1;
    }
  }
  __int128 possible = (ans * (ans - 1)) / 2;
  ans = ans + n - possible;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}