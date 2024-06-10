#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, x; cin >> n >> x;
  int a[n + 1], b[n + 1];
  a[0] = 0;
  b[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    b[i] = a[n - i + 1];
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    b[i] += b[i - 1];
  }

  int len = -1;
  for (int i = 1; i <= n; i++) {
    int sum = a[i];
    if (sum % x != 0) {
      len = i;
    }
  }

  for (int i = 1; i <= n; i++) {
    int sum = b[i];
    if (sum % x != 0) {
      len = max(len, i);
    }
  }

  cout << len << '\n';
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