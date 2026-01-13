#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int s, k, m; cin >> s >> k >> m;
  if (s <= k) {
    int ans = s - (m % k);
    ans = max(ans, 0ll);
    cout << ans << '\n';
    return;
  }

  int x = (m / k) * k;
  int ans;
  if ((m / k) & 1) {
    ans = k;
  }
  else {
    ans = s;
  }

  ans -= m - x;
  ans = max(ans, 0ll);
  cout << ans << '\n';
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