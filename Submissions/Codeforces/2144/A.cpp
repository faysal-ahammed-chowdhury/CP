#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  int a[n + 1], pref[n + 1];
  pref[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  for (int l = 1; l <= n - 2; l++) {
    for (int r = l + 1; r < n; r++) {
      int x = pref[l] % 3;
      int y = (pref[r] - pref[l]) % 3;
      int z = (pref[n] - pref[r]) % 3;
      set<int> se;
      se.insert(x);
      se.insert(y);
      se.insert(z);

      if (se.size() == 3 or se.size() == 1) {
        cout << l << ' ' << r << '\n';
        return;
      }
    }
  }

  cout << 0 << ' ' << 0 << '\n';
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