#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int b[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  bool possible = false;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    int d = a[i] - b[i];
    possible |= d >= 2;
    cnt += d >= 1;
  }

  if (possible) {
    cout << cnt + 1 << '\n';
  }
  else {
    cout << -1 << '\n';
  }

  return 0;
}