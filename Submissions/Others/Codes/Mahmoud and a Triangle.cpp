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

  sort(a + 1, a + n + 1);

  for (int i = n - 2; i >= 1; i--) {
    if (a[i] + a[i + 1] > a[i + 2]) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";

  return 0;
}