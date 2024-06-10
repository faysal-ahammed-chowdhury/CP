#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  int old_n = n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] %= k;
  }

  int mn = 100;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 0) {
      cout << 0 << '\n';
      return;
    }
    mn = min(mn, abs(a[i] - k));
  }

  if (k == 4) {
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1) cnt1++;
      else if (a[i] == 2) cnt2++;
    }

    if (cnt2 >= 2) {
      mn = min(mn, 0);
    }
    if (cnt1 >= 2) {
      mn = min(mn, 2);
    }
    if (cnt1 >= 1 and cnt2 >= 1) {
      mn = min(mn, 1);
    }
  }

  cout << mn << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}