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

  bool pref[n + 1], suff[n + 1];
  pref[1] = true; suff[n] = true;
  for (int i = 2; i <= n; i++) {
    pref[i] = pref[i - 1] and (a[i] == a[i - 1]);
  }
  for (int i = n - 1; i >= 1; i--) {
    suff[i] = suff[i + 1] and (a[i] == a[i + 1]);
  }

  int ans = 1e18;
  for (int i = 1; i <= n; i++) {
    int l = (i - 1) * a[i];
    if (pref[i]) l = 0;
    while (i + 1 <= n and a[i + 1] == a[i]) i++;
    int r = (n - i) * a[i];
    if (suff[i]) r = 0;
    ans = min(ans, l + r);
    // cout << a[i] << ' ' << ans << '\n';
  }

  assert(ans != (long long)1e18);
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