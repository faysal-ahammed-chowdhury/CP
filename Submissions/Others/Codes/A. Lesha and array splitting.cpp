#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  int a[n + 1];
  a[0] = 0;
  bool all_zero = true;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    all_zero &= a[i] == 0;
    a[i] += a[i - 1];
  }

  if (all_zero) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";
  if (a[n] != 0) {
    cout << 1 << '\n';
    cout << 1 << ' ' << n << '\n';
    return 0;
  }

  cout << 2 << '\n';
  for (int i = 1; i <= n; i++) {
    if (a[i] != 0) {
      cout << 1 << ' ' << i << '\n';
      cout << i + 1 << ' ' << n << '\n';
      return 0;
    }
  }

  return 0;
}