#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll lcm(ll a, ll b) {
  return (a * b) / gcd(a, b);
}

void solve() {
  int n; cin >> n;
  ll ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = lcm(ans, i);
  }
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