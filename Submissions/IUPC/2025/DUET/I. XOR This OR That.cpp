#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6;
int n;
int a[N];
ll ans;

void f(int i, int s1, int s2, int sz) {
  if (i > n) {
    if (sz != 0 and sz != n) ans = min(ans, 1ll * s1 * s2);
    return;
  }
  f(i + 1, (s1 ^ a[i]), s2, sz + 1);
  f(i + 1, s1, (s2 | a[i]), sz);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  if (n > 20) {
    cout << 0 << '\n';
    return;
  }

  ans = 1e18;
  f(1, 0, 0, 0);
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