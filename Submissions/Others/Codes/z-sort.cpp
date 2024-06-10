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

  for (int i = 2; i + 1 <= n; i += 2) {
    swap(a[i], a[i + 1]);
  }

  bool ok = true;
  for (int i = 2; i <= n; i += 2) {
    ok &= a[i] >= a[i - 1];
  }

  for (int i = 3; i <= n; i += 2) {
    ok &= a[i] <= a[i - 1];
  }

  if (ok) {
    for (int i = 1; i <= n; i++) {
      cout << a[i] << ' ';
    }
    cout << '\n';
  }
  else {
    cout << "Impossible\n";
  }

  return 0;
}