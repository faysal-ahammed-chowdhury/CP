#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int ans = 0;
  for (int i = 2; i <= n; i += 2) {
    int tot = a[i - 1];
    if (i + 1 <= n) tot += a[i + 1];

    if (tot <= a[i]) continue;
    int need = tot - a[i];
    ans += need;

    need -= max(0ll, a[i - 1] - a[i]);
    if (i + 1 <= n) {
      a[i + 1] -= need;
      a[i + 1] = max(a[i + 1], 0ll);
    }
  }

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