#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get(int n) {
  return (1ll * n * (n + 1)) / 2;
}

void solve() {
  int n, a, b; cin >> n >> a >> b;
  if (a >= b) {
    cout << 1ll * n * a << '\n';
  }
  else {
    int cnt = min(n, b - a);
    int rem = n - cnt;
    ll ans = get(b) - get(b - cnt);
    ans += 1ll * rem * a;
    cout << ans << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}