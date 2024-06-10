#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int a[n + 1], b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  memset(b, 0, sizeof(b));
  bool ok = true;
  for (int i = 1; i + 2 <= n; i++) {
    int rem = a[i] - b[i];
    if (rem < 0) ok = false;
    b[i] += rem;
    b[i + 1] += 2 * rem;
    b[i + 2] += rem;
  }

  for (int i = 1; i <= n; i++) {
    ok &= a[i] == b[i];
  }

  if (ok) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
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