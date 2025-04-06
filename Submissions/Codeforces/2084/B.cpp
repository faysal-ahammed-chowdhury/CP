#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1e18 + 9;

void solve() {
  int n; cin >> n;
  ll a[n + 1];
  ll mn = inf;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }

  sort(a + 1, a + n + 1);
  ll gc = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] % mn == 0) {
      gc = __gcd(a[i], gc);
    }
  }

  if (gc == mn) cout << "Yes\n";
  else cout << "No\n";
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