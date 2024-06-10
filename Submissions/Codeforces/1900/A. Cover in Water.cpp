#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  char a[n + 1];
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == '.') cnt++;
  }

  int consec = 0, mx = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == '.') {
      consec++;
    }
    else {
      mx = max(consec, mx);
      consec = 0;
    }
  }
  mx = max(consec, mx);
  if (mx > 2) {
    cout << 2 << '\n';
  }
  else {
    cout << cnt << '\n';
  }
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